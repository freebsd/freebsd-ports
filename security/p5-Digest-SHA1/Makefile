# New ports collection makefile for:	p5-Digest-SHA1
# Date created:				30 March 2001
# Whom:					Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA1
PORTVERSION=	2.07
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl interface to the SHA-1 Algorithm

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA1.3

.include <bsd.port.mk>
