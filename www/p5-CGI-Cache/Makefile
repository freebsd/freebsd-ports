# New ports collection makefile for:	CGI-Cache
# Date created:				Mon Jan  1 11:26:17 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Cache
PORTVERSION=	1.21
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl extension to cache output of time-intensive CGI scripts

BUILD_DEPENDS=	${SITE_PERL}/File/Cache.pm:${PORTSDIR}/devel/p5-File-Cache \
		${SITE_PERL}/Cache/SizeAwareFileCache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec/Functions.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL?=	${SITE_PERL}
PERL_CONFIGURE=	yes

MAN3=		CGI::Cache.3

.include <bsd.port.post.mk>
