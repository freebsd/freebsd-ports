# New ports collection makefile for:	Apache-AuthenCache
# Date created:				Sun Dec 31 19:59:31 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenCache
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that implements authentication caching

BUILD_DEPENDS=	${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/IPC/Cache.pm:${PORTSDIR}/devel/p5-IPC-Cache \
		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${SITE_PERL}
PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenCache.3

.include <bsd.port.mk>
