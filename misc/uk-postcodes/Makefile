# New ports collection makefile for:	United Kingdom post codes.
# Date created:         1998-01-01
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=       postcodes
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~wosch/src/
PKGNAMEPREFIX=	uk-
DISTFILES=	uk.postcodes.gz

MAINTAINER=     brian@FreeBSD.org

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${DISTNAME}
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${PREFIX}/share/misc

.include <bsd.port.mk>
