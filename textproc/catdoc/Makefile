# New ports collection makefile for:   catdoc
# Version required:    0.3
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id$
#

DISTNAME=	catdoc
PKGNAME=	catdoc-0.3
CATEGORIES=	textproc
# Uses on-the-fly tar, which may not work with all of MASTER_SITE_TEX_CTAN.
MASTER_SITES=	ftp://ftp.cdrom.com/pub/tex/ctan/support/
EXTRACT_SUFX=	.tar

MAINTAINER=	brion@queeg.com

EXTRACT_BEFORE_ARGS=	-xf

MAN1=		catdoc.1

# The wordview tcl/tk script is small and not required.  If the user
# has tk, it will work.  It comes preset for tk-8.0, but works with less.

# You may define LATIN1 in CFLAGS.  Little effect.  See source.
do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o catdoc catdoc.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdoc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wordview ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdoc.1 ${PREFIX}/man/man1/catdoc.1

.include <bsd.port.mk>
