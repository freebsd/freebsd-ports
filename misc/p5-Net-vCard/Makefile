# New ports collection makefile for:	p5-Net-vCard
# Date created:				16 April 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=		Net-vCard
PORTVERSION=		0.5
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=		p5-

MAINTAINER=		mat@FreeBSD.org
COMMENT=		Read and write vCard files (RFC 2426)

PERL_CONFIGURE=		yes

MAN3=			Net::vFile.3 Net::vCard.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE="Need at least perl 5.8 to build"
.endif

.include <bsd.port.post.mk>
