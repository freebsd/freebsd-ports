PORTNAME=	sslh
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	SSL/SSH multiplexer
WWW=		https://www.rutschle.net/tech/sslh.shtml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libpcre2-8.so:devel/pcre2 \
		libev.so:devel/libev

USES=		gmake
USE_RC_SUBR=	sslh
USE_GITHUB=	yes
GH_ACCOUNT=	yrutschle

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES LIBWRAP
OPTIONS_DEFAULT=LIBWRAP

LIBWRAP_MAKE_ENV=	USELIBWRAP=1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/sslh-fork \
		sbin/sslh-select \
		sbin/sslh-ev \
		"@sample etc/sslh.conf.sample"

PORTEXAMPLES=	example.cfg test.cfg udp.cfg

post-patch:
	@${REINPLACE_CMD} -Ee 's,/etc/init.d/(sslh),${PREFIX}/etc/rc.d/\1,g; \
		s,/etc/default/(sslh),${PREFIX}/etc/\1.conf,g' \
		${WRKSRC}/sslh.pod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-ev ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/basic.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
