# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	single_auth
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/dkuk/${PORTNAME}/get/
PKGNAMEPREFIX=	redmine-
DISTNAME=	${BB_COMMIT}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	SSO authentication method for Redmine

RUN_DEPENDS=	redmine-a_common_libs>0:www/redmine-a_common_libs

NO_ARCH=	yes

BB_COMMIT=	5bf59295d194

REDMINE_PLUGIN_NAME=	${PORTNAME}

WRKSRC=	${WRKDIR}/dkuk-${PORTNAME}-${BB_COMMIT}

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
