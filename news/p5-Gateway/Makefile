# New ports collection makefile for: p5-Gateway
# Version required: 0.42
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

DISTNAME=		Gateway-0.42
PKGNAME=		p5-Gateway-0.42
CATEGORIES=		news perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News

MAINTAINER=		croyle@gelemna.ft-wayne.in.us

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/News/Article.pm:${PORTSDIR}/news/p5-News-Article
RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/News/Article.pm:${PORTSDIR}/news/p5-News-Article

USE_PERL5=		yes

MAN3=			News::Gateway.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
