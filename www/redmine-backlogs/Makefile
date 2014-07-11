# $FreeBSD$

PORTNAME=	backlogs
PORTVERSION=	1.0.2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Agile plugin for Redmine

USE_GITHUB=	yes
GH_ACCOUNT=	backlogs
GH_PROJECT=	redmine_backlogs
GH_COMMIT=	1e4f1af
GH_TAGNAME=	v${PORTVERSION}

RUN_DEPENDS+=	rubygem-icalendar>=0.4.2:${PORTSDIR}/devel/rubygem-icalendar \
		rubygem-prawn>=0:${PORTSDIR}/print/rubygem-prawn \
		rubygem-holidays>=1.0.3:${PORTSDIR}/devel/rubygem-holidays \
		rubygem-open-uri-cached>=0:${PORTSDIR}/net/rubygem-open-uri-cached \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri

REDMINE_PLUGIN_NAME=	redmine_backlogs

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
