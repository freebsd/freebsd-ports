# New ports collection makefile for:	redmine-backlogs
# Date created:		2011-11-01
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	backlogs
PORTVERSION=	0.6.16
CATEGORIES=	www
MASTER_SITES=	http://people.freebsd.org/~pgollucci/ \
		LOCAL/pgollucci

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Agile plugin for Redmine

RUN_DEPENDS+=	rubygem-icalendar>=0.4.2:${PORTSDIR}/devel/rubygem-icalendar \
		rubygem-prawn>=0:${PORTSDIR}/print/rubygem-prawn \
		rubygem-holidays>=0:${PORTSDIR}/devel/rubygem-holidays \
		rubygem-open-uri-cached>=0:${PORTSDIR}/net/rubygem-open-uri-cached \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri

WRKSRC=	${WRKDIR}/relaxdiego-redmine_backlogs-061c9ac

REDMINE_PLUGIN_NAME=	redmine_backlogs

.include "${.CURDIR}/../../www/redmine/bsd.redmine.mk"
