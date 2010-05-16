# New ports collection makefile for:	p5-Mail-Cache
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Mail-Cache
PORTVERSION=	0.1.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Caches mail information

BUILD_DEPENDS=	${SITE_PERL}/File/BaseDir.pm:${PORTSDIR}/devel/p5-File-BaseDir \
		${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple

PERL_CONFIGURE=	yes

MAN3=		Mail::Cache.3

.include <bsd.port.mk>
