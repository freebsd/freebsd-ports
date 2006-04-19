# New ports collection makefile for:	Tree-Suffix
# Date created:				Apr 17 2006
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=		Tree-Suffix
PORTVERSION=		0.14
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=		p5-

MAINTAINER=		clsung@FreeBSD.org
COMMENT=		Perl interface to the libstree library

LIB_DEPENDS=		stree.0:${PORTSDIR}/textproc/libstree

PERL_CONFIGURE=		yes
CFLAGS+=		-I${LOCALBASE}/include

MAN3=			Tree::Suffix.3

.include <bsd.port.mk>
