# $FreeBSD$

PORTNAME=	open-isns
PORTVERSION=	0.99
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Internet Storage Name Service (iSNS)

LICENSE=	LGPL21

USES=		autoreconf gmake pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	open-iscsi
GH_TAGNAME=	cfdbcff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
INSTALL_TARGET=	install install_lib
USE_RC_SUBR=	isnsd
DATABASE_PLACE?=	/var/db/isns

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEV SECURITY SLP
OPTIONS_DEFAULT=	SECURITY

DEV_DESC=	Install Headers & Static lib
DEV_CONFIGURE_ENABLE=	static
DEV_VARS=	INSTALL_TARGET+=install_hdrs

SECURITY_DESC=	Enable iSNS authentication
SECURITY_CONFIGURE_WITH=	security
SECURITY_USES=	ssl

SLP_DESC=	Enable SLP for server discovery
SLP_CONFIGURE_WITH=	slp
SLP_LIB_DEPENDS=	libslp.so:net/openslp
SLP_CPPFLAGS=	-I${PREFIX}/include
SLP_LDFLAGS=	-L${PREFIX}/lib

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -E \
		-e "s|^([[:blank:]]*#define ISNS_ETCDIR[[:blank:]]+\")(.*)$$|\1${PREFIX}\2|" \
		-e "s|^([[:blank:]]*#define ISCSI_DEFAULT_INITIATORNAME[[:blank:]]+\")(.*)$$|\1${PREFIX}\2|" \
		${WRKSRC}/include/libisns/paths.h.in
	${REINPLACE_CMD} -E \
		-e "1,10s|^(vardir[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${DATABASE_PLACE}|" \
		${WRKSRC}/Makefile.in
.for FILE in isnsadm.conf isnsd.conf isnsdd.conf
	${REINPLACE_CMD} -E \
		-e "s|^(.*AuthKeyFile[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${PREFIX}\2|" \
		-e "s|^(.*ServerKeyFile[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${PREFIX}\2|" \
		-e "s|^(.*Database[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${DATABASE_PLACE}|" \
		${WRKSRC}/etc/${FILE}
.endfor

post-patch-SLP-off:
	${REINPLACE_CMD} -E \
		-e "s|^(.*SLPRegister[[:blank:]]*=[[:blank:]]*)(.*)$$|\10|" \
		${WRKSRC}/etc/isnsd.conf

post-install:
.for FILE in sbin/isnsadm sbin/isnsd sbin/isnsdd lib/libisns.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${FILE}
.endfor

.include <bsd.port.mk>
