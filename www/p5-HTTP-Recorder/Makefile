# New ports collection makefile for:	p5-HTTP-Recorder
# Date created:				1 April 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	HTTP-Recorder
PORTVERSION=	0.03.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/L/LE/LEIRA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/_\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Record interaction with websites

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Recorder.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	 @${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/;' \
			-e '$$_ = "" if /use warnings/;' \
		      ${WRKSRC}/lib/HTTP/Recorder.pm \
		      ${WRKSRC}/lib/HTTP/Recorder/Logger.pm
.endif

.include <bsd.port.post.mk>
