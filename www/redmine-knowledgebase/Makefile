# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	knowledgebase
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	redmine-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Knowledgebase functionality for Redmine

LICENSE=	MIT

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	alexbevi
GH_PROJECT=	redmine_knowledgebase

REDMINE_PLUGIN_NAME=	redmine_${PORTNAME}

RUN_DEPENDS+=	rubygem-redmine_acts_as_taggable_on>0:www/rubygem-redmine_acts_as_taggable_on \
		rubygem-ya2yaml>0:textproc/rubygem-ya2yaml \
		rubygem-awesome_nested_set>0:databases/rubygem-awesome_nested_set

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
