# New ports collection makefile for:	p5-WebService-Basecamp
# Date created:		2006-08-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WebService-Basecamp
PORTVERSION=	0.1.4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WebService
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Basecamp API webservice

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::Basecamp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from www/p5-libwww
IGNORE=		requires Perl 5.6.0 or newer. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
