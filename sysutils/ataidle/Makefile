# Created by: Bruce Cran <bruce@cran.org.uk>
# $FreeBSD$

PORTNAME=	ataidle
PORTVERSION=	2.7.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cran.org.uk/~brucec/software/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to spin down ATA drives

USE_RC_SUBR=	${PORTNAME}
MAN8=		ataidle.8
PORTDOCS=	COPYING Changelog README
PLIST_FILES=	sbin/ataidle

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ataidle ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ataidle.8 ${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
