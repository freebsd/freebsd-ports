# New ports collection makefile for:	Apache-AuthenURL
# Date created:				Sun Dec 31 20:08:48 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenURL
PORTVERSION=	0.8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Apache/mod_perl module to handle auth against external URLs

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Apache/AuthenCache.pm:${PORTSDIR}/www/p5-Apache-AuthenCache
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AuthenURL.3

.include <bsd.port.mk>
