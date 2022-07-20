PORTNAME=	sslh
PORTVERSION=	1.22c
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	SSL/SSH multiplexer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libpcre2-8.so:devel/pcre2

USES=		gmake
USE_RC_SUBR=	sslh
USE_GITHUB=	yes
GH_ACCOUNT=	yrutschle

OPTIONS_DEFINE=	EXAMPLES LIBWRAP
OPTIONS_DEFAULT=LIBWRAP

LIBWRAP_MAKE_ENV=	USELIBWRAP=1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/sslh-fork \
		sbin/sslh-select \
		"@sample etc/sslh.conf.sample" \
		man/man8/sslh.8.gz

PORTEXAMPLES=	example.cfg test.cfg udp.cfg

post-patch:
	@${REINPLACE_CMD} -Ee 's,/etc/init.d/(sslh),${PREFIX}/etc/rc.d/\1,g; \
		s,/etc/default/(sslh),${PREFIX}/etc/\1.conf,g' \
		${WRKSRC}/sslh.pod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/basic.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_MAN} ${WRKSRC}/sslh.8.gz ${STAGEDIR}${MANPREFIX}/man/man8

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
