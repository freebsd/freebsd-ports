# New ports collection makefile for:	Tree-Suffix
# Date created:				Apr 17 2006
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Tree-Suffix
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to the libstree library

LIB_DEPENDS=	stree.0:${PORTSDIR}/textproc/libstree

PERL_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		Tree::Suffix.3

.include <bsd.port.mk>
