# Created by: Bruce Cran <bruce@cran.org.uk>
# $FreeBSD$

PORTNAME=	ataidle
PORTVERSION=	2.7.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cran.org.uk/~brucec/software/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to spin down ATA drives

USE_RC_SUBR=	${PORTNAME}
PORTDOCS=	COPYING Changelog README
PLIST_FILES=	sbin/ataidle \
		man/man8/ataidle.8.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ataidle ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ataidle.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
