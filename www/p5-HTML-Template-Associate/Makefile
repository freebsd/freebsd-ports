# New ports collection makefile for:	HTML-Template-Associate
# Date created:				2 Sep 2003
# Whom:					Manuel Rábade <mig@mig-29.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-Associate
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AL/ALEXP
PKGNAMEPREFIX=	p5-

MAINTAINER=	mig@mig-29.net
COMMENT=	Bridges gap between HTML::Template and other modules

RUN_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/CGI/Base.pm:${PORTSDIR}/www/p5-CGI-modules \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator

PERL_CONFIGURE=	yes

MAN3=		HTML::Template::Associate.3 \
		HTML::Template::Associate::FormValidator.3

.include <bsd.port.mk>
