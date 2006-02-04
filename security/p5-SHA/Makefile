# New ports collection makefile for:	p5-SHA
# Date created:				Sep 30, 2002
# Whom:	      				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	SHA
PORTVERSION=	2.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GA/GAAS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	jim@corebsd.or.id
COMMENT=	Perl5 interface to the SHA1 algorithm

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SHA.3

.include <bsd.port.mk>
