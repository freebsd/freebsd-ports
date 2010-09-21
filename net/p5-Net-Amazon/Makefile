# New ports collection makefile for:	Net-Amazon
# Date created:	   			Oct 23 2003 \
# Whom:		   			clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon
PORTVERSION=	0.59
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

.include "Makefile.man"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
