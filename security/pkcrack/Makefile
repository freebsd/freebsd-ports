# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	pkcrack
PORTVERSION=	1.2.2
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~conrad/krypto/pkcrack/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A utility for breaking pkzip encryption

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PLIST_FILES=	bin/pkextract bin/pkfindkey bin/pkmakekey bin/pkcrack bin/zipdecrypt
PORTDOCS=	README pkzip.ps.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.for f in pkcrack zipdecrypt
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
# these file names are too generic
.for f in extract findkey makekey
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/pk${f}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
