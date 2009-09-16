# New ports collection makefile for:    p5-TestGen4Web-Runner
# Date created:				June 13th, 2006
# Whom:	      				Conor McDermottroe <ports@mcdermottroe.com>
# ex:ts=8
#
# $FreeBSD$
#

PORTNAME=	TestGen4Web-Runner
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	WWW/MACKERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A PERL module to replay files recorded with TestGen4Web

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		TestGen4Web::Runner.3

.include <bsd.port.mk>
