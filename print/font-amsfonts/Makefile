# New ports collection makefile for:	font-amsfonts
# Date created:		June 13, 2011
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	amsfonts
PORTVERSION=	3.02
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
PKGNAMEPREFIX=	font-
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern and standard fonts for TeX

PLIST_SUB=	FONTSDIR=${FONTSDIR}
NO_BUILD=	yes

FONTSDIR=	share/fonts/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	cd ${PREFIX}/${FONTSDIR} && ${TAR} -x -z -U --strip-components 1 -f \
	    ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
