# $FreeBSD$

PORTNAME=	backlogs
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Agile plugin for Redmine

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-holidays>=1.0.3:${PORTSDIR}/devel/rubygem-holidays \
		rubygem-icalendar>=0.4.2:${PORTSDIR}/devel/rubygem-icalendar \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-open-uri-cached>=0:${PORTSDIR}/net/rubygem-open-uri-cached \
		rubygem-prawn>=0:${PORTSDIR}/print/rubygem-prawn

REDMINE_PLUGIN_NAME=	redmine_backlogs

USE_GITHUB=	yes
GH_PROJECT=	redmine_backlogs

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
