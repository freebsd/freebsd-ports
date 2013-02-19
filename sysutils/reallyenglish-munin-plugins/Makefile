# New ports collection makefile for:	reallyenglish-munin-plugins
# Date created:		2011-02-05
# Whom:			Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
#
# $FreeBSD$
#

PORTNAME=	reallyenglish-munin-plugins
PORTVERSION=	1.3
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.reallyenglish.com/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	3rd-party munin plugins for reallyenglish

RUN_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	munin-node>0:${PORTSDIR}/sysutils/munin-node

MAKE_ARGS=	DESTDIR=${PREFIX}
SUB_FILES=	pkg-install

.include <bsd.port.mk>
