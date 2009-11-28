# New ports collection makefile for:	fontconfig-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	5
PORTEPOCH=	0

DOCSDIR=	${PREFIX}/share/doc/fontconfig-devel

.include "${.CURDIR}/Makefile.man"

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${PREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fontconfig-devel.pdf \
		${WRKSRC}/doc/fontconfig-devel.txt ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/fontconfig-devel/* ${DOCSDIR}/html
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
