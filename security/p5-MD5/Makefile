# New ports collection makefile for:	p5-MD5
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MD5
PORTVERSION=	2.03
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MD5/GAAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 interface to MD5 Message-Digest Algorithm

PERL_CONFIGURE=	yes

MAN3=		MD5.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
