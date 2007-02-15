# New ports collection makefile for:	math/p5-Set-IntSpan-Fast
# Date created:				15 February 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Set-IntSpan-Fast
PORTVERSION=	0.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast handling of sets containing integer spans

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/Data/Types.pm:${PORTSDIR}/devel/p5-Data-Types \
		${SITE_PERL}/Class/Std.pm:${PORTSDIR}/devel/p5-Class-Std
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Set::IntSpan::Fast.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
