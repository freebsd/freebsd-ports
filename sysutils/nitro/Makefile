PORTNAME=	nitro
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://git.vuxu.org/nitro/snapshot/

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Minimal init implementation and process supervisor
WWW=		https://git.vuxu.org/nitro/about/

LICENSE=	ISCL
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/LICENSE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nitro ${STAGEDIR}${PREFIX}/bin/nitro
	${INSTALL_PROGRAM} ${WRKSRC}/nitroctl ${STAGEDIR}${PREFIX}/bin/nitroctl
	${INSTALL_MAN} ${WRKSRC}/nitro.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/nitroctl.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
