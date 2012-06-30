# New ports collection makefile for:	p5-ZConf-RSS-GUI-GTK
# Date created:		2009-11-09
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-RSS-GUI-GTK
PORTVERSION=	0.0.1
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a GTK backend for ZConf::RSS::GUI

RUN_DEPENDS=	p5-ZConf-RSS>=0:${PORTSDIR}/www/p5-ZConf-RSS \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

PERL_CONFIGURE=	yes

MAN3=		ZConf::RSS::GUI::GTK.3

.include <bsd.port.mk>
