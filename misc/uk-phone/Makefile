# New ports collection makefile for:	United Kingdom phone codes.
# Version required:     1.0
# Date created:         1998-01-01
# Whom:                 wosch
#
# $FreeBSD$
#

DISTNAME=	uk.phone
PKGNAME=        uk-phone-1.0
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL} \
		http://www.freebsd.org/~wosch/src/
EXTRACT_SUFX=	.gz

MAINTAINER=     brian@FreeBSD.org

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${DISTNAME}
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/misc

.include <bsd.port.mk>
