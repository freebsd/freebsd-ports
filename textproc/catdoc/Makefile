# New ports collection makefile for:   catdoc
# Version required:    0.3
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id: Makefile,v 1.4 1998/06/18 14:53:03 hoek Exp $
#

DISTNAME=	catdoc-0.35
CATEGORIES=	textproc
MASTER_SITES=	http://www.ice.ru/~vitus/works/

MAINTAINER=	brion@queeg.com

MAN1=		catdoc.1

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

# The wordview tcl/tk script is small and not required.  If the user
# has tk, it will work.  It comes preset for tcl/tk-8.0, but works with tcl-76.

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o catdoc catdoc.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdoc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wordview ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdoc.1 ${PREFIX}/man/man1/catdoc.1

.include <bsd.port.mk>
