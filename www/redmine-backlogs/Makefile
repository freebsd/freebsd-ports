# $FreeBSD$

PORTNAME=	backlogs
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Agile plugin for Redmine

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-holidays>=1.0.3:${PORTSDIR}/devel/rubygem-holidays \
		rubygem-icalendar>=0.4.2:${PORTSDIR}/devel/rubygem-icalendar \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-open-uri-cached>=0:${PORTSDIR}/net/rubygem-open-uri-cached \
		rubygem-prawn>=0:${PORTSDIR}/print/rubygem-prawn

NO_ARCH=	yes
USES=		shebangfix
SHEBANG_FILES=	lib/ci/__buildscript.sh \
		lib/ci/generate.sh \
		rbl-test

REDMINE_PLUGIN_NAME=	redmine_backlogs

USE_GITHUB=	yes
GH_PROJECT=	redmine_backlogs

post-patch:
	@${RM} ${WRKSRC}/test.rb

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
