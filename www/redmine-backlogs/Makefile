# $FreeBSD$

PORTNAME=	backlogs
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Agile plugin for Redmine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-holidays>=1.0.3:devel/rubygem-holidays \
		rubygem-icalendar>=0.4.2:devel/rubygem-icalendar \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-open-uri-cached>=0:net/rubygem-open-uri-cached \
		rubygem-prawn>=0:print/rubygem-prawn

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
