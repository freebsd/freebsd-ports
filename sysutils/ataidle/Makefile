# Created by: Bruce Cran <bruce@cran.org.uk>
# $FreeBSD$

PORTNAME=	ataidle
PORTVERSION=	2.7.2
CATEGORIES=	sysutils
MASTER_SITES=	http://bluestop.org/ataidle/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to spin down ATA drives

LICENSE=	BSD

USE_RC_SUBR=	${PORTNAME}
PORTDOCS=	Changelog README
PLIST_FILES=	sbin/ataidle \
		man/man8/ataidle.8.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ataidle ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ataidle.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
