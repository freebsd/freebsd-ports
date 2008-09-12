# New ports collection makefile for: p5-Gateway
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	Gateway
PORTVERSION=	0.42
PORTREVISION=	1
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robomoderation and mail to news gatewaying toolkit

BUILD_DEPENDS=	${SITE_PERL}/News/Article.pm:${PORTSDIR}/news/p5-News-Article
RUN_DEPENDS=	${SITE_PERL}/News/Article.pm:${PORTSDIR}/news/p5-News-Article

PERL_CONFIGURE=	yes

MAN3=		News::Gateway.3

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${PREFIX} ${EXAMPLESDIR}
.for file in listgate listgate.m4 listgate.readme raccmod raccpost racrmod
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
