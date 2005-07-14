# New ports collection makefile for:	p5-CGI-SSI
# Date created:				09 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-SSI
PORTVERSION=	0.86
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use SSI from CGI scripts

BUILD_DEPENDS=	${SITE_PERL}/HTML/SimpleParse.pm:${PORTSDIR}/www/p5-HTML-SimpleParse \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::SSI.3

.include <bsd.port.mk>
