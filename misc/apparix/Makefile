# New ports collection makefile for:    apparix
# Date created:         16 Apr 2006
# Whom:                 Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$
#

PORTNAME=	apparix
PORTVERSION=	20081026
CATEGORIES=	misc
MASTER_SITES=	http://micans.org/apparix/src/
DISTNAME=	${PORTNAME}-08-331

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bookmark directories and apparate inside them

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no

MAN1=		apparix.1
PORTDOCS=	apparix.azm apparix.html apparix.ps
PLIST_FILES=	bin/apparix

post-patch:
	@${REINPLACE_CMD} -e 's|sig_atomic_t|int|g' ${WRKSRC}/util/err.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
