# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Search-Odeum
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to the Odeum inverted index API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libqdbm.so:${PORTSDIR}/databases/qdbm

CFLAGS+=	-I${LOCALBASE}/include
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
