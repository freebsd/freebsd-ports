# New ports collection makefile for:	pkcrack
# Date created:				27 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	pkcrack
PORTVERSION=	1.2.2
CATEGORIES=	security
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~conrad/krypto/pkcrack/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A utility for breaking pkzip encryption

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PLIST_FILES=	bin/pkextract bin/pkfindkey bin/pkmakekey bin/pkcrack bin/zipdecrypt
PORTDOCS=	README pkzip.ps.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^\(#include\ <\)malloc\.h>|\1stdlib.h>|' \
		${WRKSRC}/exfunc.c \
		${WRKSRC}/readhead.c
	@${REINPLACE_CMD} -e '/<malloc\.h>/d' \
		${WRKSRC}/extract.c \
		${WRKSRC}/main.c \
		${WRKSRC}/zipdecrypt.c
	@${REINPLACE_CMD} -E 's/^(CC|CFLAGS)=/\1?=/' \
		${WRKSRC}/Makefile

do-install:
.for f in pkcrack zipdecrypt
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
# these file names are too generic
.for f in extract findkey makekey
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/pk${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
