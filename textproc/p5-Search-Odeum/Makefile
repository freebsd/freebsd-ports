# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Search-Odeum
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl interface to the Odeum inverted index API

LIB_DEPENDS=	libqdbm.so:${PORTSDIR}/databases/qdbm

CFLAGS+=	-I${LOCALBASE}/include
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
