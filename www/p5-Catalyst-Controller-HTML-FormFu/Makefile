# New ports collection makefile for:	p5-Catalyst-Controller-HTML-FormFu
# Date created:		2007-12-24
# Whom:			Andrej Zverev <andrey.zverev@electro-com.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-HTML-FormFu
PORTVERSION=	0.03000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/C/CF/CFRANKS
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Catalyst FormFu Base Controller

RUN_DEPENDS=	p5-HTML-FormFu>=0.03000:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-NEXT>=0:${PORTSDIR}/devel/p5-NEXT \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Controller::HTML::FormFu.3 \
	Catalyst::Helper::HTML::FormFu.3

.include <bsd.port.mk>
