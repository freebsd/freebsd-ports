# New ports collection makefile for: p5-Gateway
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	Gateway
PORTVERSION=	0.42
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-

MAINTAINER=	croyle@gelemna.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Article.pm:${PORTSDIR}/news/p5-News-Article
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Article.pm:${PORTSDIR}/news/p5-News-Article

PERL_CONFIGURE=	yes

MAN3=		News::Gateway.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/Gateway
.for file in listgate listgate.m4 listgate.readme raccmod raccpost racrmod
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/share/examples/Gateway
.endfor
.endif

.include <bsd.port.mk>
