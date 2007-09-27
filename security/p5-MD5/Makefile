# New ports collection makefile for:	p5-MD5
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MD5
PORTVERSION=	2.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	${PORTNAME}/GAAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	wrapper to the Digest::MD5 module

PERL_CONFIGURE=	yes

MAN3=		MD5.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
