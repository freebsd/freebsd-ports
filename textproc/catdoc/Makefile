# New ports collection makefile for:   catdoc
# Version required:    0.3
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id: Makefile,v 1.2 1998/02/22 22:26:23 wosch Exp $
#

DISTNAME=	catdoc-0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/catdoc
DISTFILES=	catdoc.c catdoc.1 wordview

MAINTAINER=	brion@queeg.com

DIST_SUBDIR=	catdoc
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

MAN1=		catdoc.1

# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1

# The wordview tcl/tk script is small and not required.  If the user
# has tk, it will work.  It comes preset for tk-8.0, but works with less.

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o catdoc catdoc.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdoc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wordview ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdoc.1 ${PREFIX}/man/man1/catdoc.1

.include <bsd.port.mk>
