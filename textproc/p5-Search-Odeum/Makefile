# New ports collection makefile for:	p5-Search-Odeum
# Date created:		2007-07-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Search-Odeum
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl interface to the Odeum inverted index API

LIB_DEPENDS=	qdbm:${PORTSDIR}/databases/qdbm

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
PERL_CONFIGURE=	yes

MAN3=		Search::Odeum.3 \
		Search::Odeum::Document.3 \
		Search::Odeum::Result.3

.include <bsd.port.mk>
