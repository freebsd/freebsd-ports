# New ports collection makefile for:	p5-ZConf-RSS-GUI-GTK
# Date created:		2009-11-09
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-RSS-GUI-GTK
PORTVERSION=	0.0.1
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a GTK backend for ZConf::RSS::GUI

RUN_DEPENDS=	${SITE_PERL}/ZConf/RSS.pm:${PORTSDIR}/www/p5-ZConf-RSS \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

PERL_CONFIGURE=	yes

MAN3=		ZConf::RSS::GUI::GTK.3

.include <bsd.port.mk>
