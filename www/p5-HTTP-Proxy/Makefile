# New ports collection makefile for:	p5-HTTP-Proxy
# Date created:				16 April 2003
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	HTTP-Proxy
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A pure Perl HTTP proxy

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		\
		HTTP::Proxy.3 \
		HTTP::Proxy::BodyFilter.3 \
		HTTP::Proxy::BodyFilter::htmlparser.3 \
		HTTP::Proxy::BodyFilter::htmltext.3 \
		HTTP::Proxy::BodyFilter::lines.3 \
		HTTP::Proxy::BodyFilter::simple.3 \
		HTTP::Proxy::BodyFilter::tags.3 \
		HTTP::Proxy::HeaderFilter.3 \
		HTTP::Proxy::HeaderFilter::simple.3 \
		HTTP::Proxy::HeaderFilter::standard.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/INET.pm:${PORTSDIR}/devel/p5-IO
EXTRA_PATCHES=	${PATCHDIR}/5.005-Makefile.PL ${PATCHDIR}/5.005-lib::HTTP::Proxy.pm ${PATCHDIR}/5.005-lib::HTTP::Proxy::BodyFilter::htmltext.pm

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
.endif

.include <bsd.port.post.mk>
