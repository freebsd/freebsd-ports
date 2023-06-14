PORTNAME=	open-isns
DISTVERSIONPREFIX=	v
DISTVERSION=	0.101
CATEGORIES=	net

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Internet Storage Name Service (iSNS)
WWW=		https://github.com/open-iscsi/open-isns/

LICENSE=	LGPL21

USES=	autoreconf gmake pathfix python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	open-iscsi

USE_LDCONFIG=	yes
USE_RC_SUBR=	isnsd
SHEBANG_FILES=	isnssetup ${TEST_WRKSRC}/*.py ${TEST_WRKSRC}/*.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
INSTALL_TARGET=	install install_lib
TEST_ARGS=	LD_LIBRARY_PATH=${WRKSRC}
TEST_WRKSRC=	${WRKSRC}/tests

OPTIONS_DEFINE=	DEV SECURITY SLP
OPTIONS_DEFAULT=	SECURITY
OPTIONS_SUB=	yes

DEV_DESC=	Install Headers & Static lib
SECURITY_DESC=	Enable iSNS authentication
SLP_DESC=	Enable SLP for server discovery

DEV_CONFIGURE_ENABLE=	static
DEV_VARS=	INSTALL_TARGET+=install_hdrs

SECURITY_USES=	ssl
SECURITY_CONFIGURE_WITH=	security
SECURITY_TEST_TARGET=	tests
SECURITY_TEST_TARGET_OFF=	tests-no-security

SLP_LIB_DEPENDS=	libslp.so:net/openslp
SLP_CONFIGURE_WITH=	slp
SLP_CPPFLAGS=	-I${PREFIX}/include
SLP_LDFLAGS=	-L${PREFIX}/lib

_DATABASE_PLACE?=	${DESTDIR}/var/db/isns

.include <bsd.port.options.mk>

post-patch:
	#
	# Move paths to configurations according to the variable ${PREFIX} and ${_DATABASE_PLACE}.
	${REINPLACE_CMD} -E \
		-e "s|(/etc/)|${PREFIX}\1|g" \
		-e "s|^(.*Database[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${_DATABASE_PLACE}|" \
		${WRKSRC}/etc/isnsadm.conf \
		${WRKSRC}/etc/isnsd.conf \
		${WRKSRC}/etc/isnsdd.conf \
		${WRKSRC}/isnssetup \
		${WRKSRC}/include/libisns/paths.h.in
	#
	# Move paths to configurations according to the variables ${PREFIX} and ${_DATABASE_PLACE}, remove the dependencies on the systemd.
	${REINPLACE_CMD} -E \
		-e "1,12s|(/etc)|${PREFIX}\1|" \
		-e "1,12s|^(vardir[[:blank:]]*=[[:blank:]]*)(.*)$$|\1${_DATABASE_PLACE}|" \
		-e "s|^(.*)[[:blank:]]+\\$$\(SYSTEMDDIR\)$$|\1|" \
		-e "/isnsd\.(service|socket)/d" \
		${WRKSRC}/Makefile.in
	#
	# Move paths to configurations according to the variable ${PREFIX}, remove bashism.
	${REINPLACE_CMD} -E \
		-e "1,3s|ba(sh)|\1|" \
		-e "1,27s|(/etc/)|${PREFIX}\1|g" \
		-e "s|^[[:blank:]]*function[[:blank:]]+([^[:blank:]]+)(.*)$$|\1()\2|" \
		${WRKSRC}/tests/genkey

post-patch-SLP-off:
	${REINPLACE_CMD} -E -i.bak-SLP \
		-e "s|^(.*SLPRegister[[:blank:]]*=[[:blank:]]*)(.*)$$|\10|" \
		${WRKSRC}/etc/isnsd.conf

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/isnssetup ${STAGEDIR}${PREFIX}/sbin
	${FIND} ${STAGEDIR}${PREFIX}/etc/isns -type f -a -name '*.conf' -exec ${MV} '{}' '{}.sample' ';'
.for FILE in sbin/isnsadm sbin/isnsd sbin/isnsdd lib/libisns.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${FILE}
.endfor

.include <bsd.port.mk>
