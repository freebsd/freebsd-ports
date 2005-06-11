# New ports collection makefile for:	CGI-Cache
# Date created:				Mon Jan  1 11:26:17 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Cache
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl extension to cache output of time-intensive CGI scripts

BUILD_DEPENDS=	${SITE_PERL}/File/Cache.pm:${PORTSDIR}/devel/p5-File-Cache \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Cache/SizeAwareFileCache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Cache.3

.include <bsd.port.mk>
