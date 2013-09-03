# New ports collection makefile for:	HTML-Template-Associate
# Date created:				2 Sep 2003
# Whom:					Manuel Rábade <mig@mig-29.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-Associate
PORTVERSION=	2.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEXP
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Bridges gap between HTML::Template and other modules

RUN_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-Data-FormValidator>=0:${PORTSDIR}/textproc/p5-Data-FormValidator
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Template::Associate.3 \
		HTML::Template::Associate::DBI.3 \
		HTML::Template::Associate::FormValidator.3

.include <bsd.port.mk>
