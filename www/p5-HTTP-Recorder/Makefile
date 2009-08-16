# New ports collection makefile for:	p5-HTTP-Recorder
# Date created:				1 April 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	HTTP-Recorder
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/L/LE/LEIRA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Record interaction with websites

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTTP/Request/Params.pm:${PORTSDIR}/www/p5-HTTP-Request-Params
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Recorder.3

.include <bsd.port.mk>
