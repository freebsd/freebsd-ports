# New ports collection makefile for:	p5-openxpki-client-html-mason
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-client-html-mason
PORTVERSION=	0.9.546
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openxpki
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-HTML-Mason-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@cryptocom.ru
COMMENT=	Web interface for local openxpki daemon

BUILD_DEPENDS=	\
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client \
	${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client::HTML::Mason.3 \
	OpenXPKI::Client::HTML::Mason::Javascript.3 \
	OpenXPKI::Client::HTML::Mason::Menu.3
USE_PERL5=	yes
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

.include <bsd.port.mk>
