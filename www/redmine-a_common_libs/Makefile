# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a_common_libs
PORTVERSION=	2.1.8
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/dkuk/${PORTNAME}/get/
PKGNAMEPREFIX=	redmine-
DISTNAME=	${BB_COMMIT}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Common libraries for RedMine

NO_ARCH=	yes

BB_COMMIT=	a7b8c62fe17d

REDMINE_PLUGIN_NAME=	${PORTNAME}

WRKSRC=	${WRKDIR}/dkuk-${PORTNAME}-${BB_COMMIT}

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
