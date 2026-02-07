PORTNAME=	ts-warp
DISTVERSION=	1.5.8
CATEGORIES=	net

MAINTAINER=	zmey20000@yahoo.com
COMMENT=	Transparent proxy server and traffic wrapper
WWW=		https://github.com/mezantrop/ts-warp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	mezantrop

USE_RC_SUBR=	tswarp

do-install:
	${MKDIR} ${STAGEDIR}/var/db/ts-warp
	${INSTALL_PROGRAM} ${WRKSRC}/ts-warp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ts-pass ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/ts-warp.ini \
		${STAGEDIR}${PREFIX}/etc/ts-warp.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/ts-warp_pf_freebsd.conf \
		${STAGEDIR}${PREFIX}/etc/ts-warp_pf.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/ts-pass.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/ts-warp.sh.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/ts-warp.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/ts-warp.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
