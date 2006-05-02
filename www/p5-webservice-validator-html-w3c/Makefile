# New ports collection makefile for:	p5-WebService-Validator-HTML-W3C
# Date created:				Oct 10, 2005
# Whom:					toni.viemero@iki.fi
#
# $FreeBSD$
#

PORTNAME=	WebService-Validator-HTML-W3C
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WebService
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Access to the W3Cs online HTML validator

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	WebService::Validator::HTML::W3C::Error.3 \
	WebService::Validator::HTML::W3C.3

.include <bsd.port.mk>
