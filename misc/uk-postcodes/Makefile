# New ports collection makefile for:	United Kingdom post codes.
# Date created:         1998-01-01
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=       postcodes
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	wosch/src asami/LOCAL_PORTS
PKGNAMEPREFIX=	uk-
DISTFILES=	uk.postcodes.gz

MAINTAINER=     brian@FreeBSD.org

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/uk.postcodes
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/uk.postcodes ${PREFIX}/share/misc

.include <bsd.port.mk>
