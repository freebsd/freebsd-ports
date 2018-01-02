# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldap_sync
PORTVERSION=	2.0.8
CATEGORIES=	www
PKGNAMEPREFIX=	redmine-
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	LDAP user/group synchronization for Redmine

LICENSE=	GPLv3+

NO_ARCH=	yes

USES=		shebangfix
SHEBANG_FILES=	test/fixtures/ldap/names.rb

USE_GITHUB=	yes
GH_ACCOUNT=	thorin
GH_PROJECT=	redmine_${PORTNAME}

REDMINE_PLUGIN_NAME=	redmine_${PORTNAME}

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
