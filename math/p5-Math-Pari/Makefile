# New ports collection makefile for:	p5-Math-Pari
# Date created:				Tue Sep 11 02:08:49 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Pari
PORTVERSION=	2.010500
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	PARI - numerical/scientific/number-theoretic calculations

BUILD_DEPENDS=	pari:${PORTSDIR}/math/pari:configure

PERL_CONFIGURE=	yes

MAN3=		Math::Pari.3 Math::libPARI.3 \
		Math::PariInit.3 Math::libPARI.dumb.3

.include <bsd.port.pre.mk>

PARI_PORT?=	math/pari
PARI_PORTDIR?=	${PORTSDIR}/${PARI_PORT}
PARI_WRKSRC!=	cd ${PARI_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ARGS=	paridir=${PARI_WRKSRC}

post-clean:
	@cd ${PARI_PORTDIR} && ${MAKE} -DBATCH clean

.include <bsd.port.post.mk>
