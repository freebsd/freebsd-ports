# New ports collection makefile for:	p5-NewsLib
# Date created:				13 November 2004
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	NewsLib
PORTVERSION=	0.84
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of perl modules for managing Network News services

BUILD_DEPENDS=	${SITE_PERL}/News/Article.pm:${PORTSDIR}/news/p5-News-Article \
		${SITE_PERL}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::NNTP::Auth.3 \
		Net::NNTP::Client.3 \
		Net::NNTP::Functions.3 \
		Net::NNTP::Proxy.3 \
		News::Article::Cancel.3 \
		News::Article::Clean.3 \
		News::Article::Ref.3 \
		News::Article::Response.3 \
		News::NNTPAuth.3

.include <bsd.port.mk>
