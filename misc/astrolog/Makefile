# New ports collection makefile for:    astrolog
# Version required:     5.0
# Date created:         31 July 1995
# Whom:                 faulkner@cactus.org
#
# $Id: Makefile,v 1.2 1995/08/26 05:57:08 asami Exp $
#

DISTNAME=       ast50unx
PKGNAME=	astrolog-5.0
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.kiae.su/unix/magick/astrology/
EXTRACT_SUFX=	.shar.gz

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| tr -d "\r" |sh
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
