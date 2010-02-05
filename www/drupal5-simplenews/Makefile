# New ports collection makefile for:	drupal5-simplenews
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	simplenews
DISTVERSION=	5.x-1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	g_glasson@jimali.dyndns.org
COMMENT=	A simple newsletter module which allows both anonymous as well as registered users to subscribe to different newsletters.

DRUPAL5_MODULE=	yes
MODULE_DIRS=	po
MODULE_FILES=	simplenews.info simplenews.install simplenews.module sn-cron.png sn-saved.png \
		sn-sent.png sn-term.png \
		po/cs.po \
		po/da.po \
		po/de.po \
		po/es.po \
		po/fr.po \
		po/he.po \
		po/hu.po \
		po/it.po \
		po/nl.po \
		po/pt.po \
		po/sv.po \
		po/simplenews.pot

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
