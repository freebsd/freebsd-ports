# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a_common_libs
PORTVERSION=	2.4.6
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/dkuk/${PORTNAME}/get/
PKGNAMEPREFIX=	redmine-
DISTNAME=	${BB_COMMIT}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common libraries for RedMine

RUN_DEPENDS=	rubygem-activerecord-session_store>0:databases/rubygem-activerecord-session_store

NO_ARCH=	yes

BB_COMMIT=	7c2f0ce66275

REDMINE_PLUGIN_NAME=	${PORTNAME}

WRKSRC=	${WRKDIR}/dkuk-${PORTNAME}-${BB_COMMIT}

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
