# New ports collection makefile for:	USA zipcodes
# Version required:     1.0
# Date created:         1997-12-30
# Whom:                 wosch
#
# $FreeBSD$
#

DISTNAME=	zipcodes
PKGNAME=        us-zipcodes-1.0
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL} \
		http://www.freebsd.org/~wosch/src/
EXTRACT_SUFX=	.gz

MAINTAINER=     ports@FreeBSD.org

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/zipcodes
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/zipcodes ${PREFIX}/share/misc/us.zipcodes

.include <bsd.port.mk>
