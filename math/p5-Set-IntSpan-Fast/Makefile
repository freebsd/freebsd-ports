# New ports collection makefile for:	math/p5-Set-IntSpan-Fast
# Date created:				15 February 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Set-IntSpan-Fast
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast handling of sets containing integer spans

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/Data/Types.pm:${PORTSDIR}/devel/p5-Data-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Set::IntSpan::Fast.3

.include <bsd.port.mk>
