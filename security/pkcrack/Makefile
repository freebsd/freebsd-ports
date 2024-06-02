PORTNAME=	pkcrack
DISTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~conrad/krypto/pkcrack/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for breaking pkzip encryption
WWW=		https://www.unix-ag.uni-kl.de/~conrad/krypto/pkcrack.html

LICENSE=	pkcrack
LICENSE_NAME=	pkcrack non-commercial license
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/doc/README
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/pkcrack \
		bin/pkextract \
		bin/pkfindkey \
		bin/pkmakekey \
		bin/zipdecrypt
PORTDOCS=	README pkzip.ps.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|ifdef|.ifdef|g' \
	    ${PATCH_WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|endif|.endif|g' \
	    ${PATCH_WRKSRC}/Makefile

do-install:
.for f in pkcrack zipdecrypt
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
# these file names are too generic
.for f in extract findkey makekey
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/pk${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
