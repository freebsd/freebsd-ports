# Created by: clsung
# $FreeBSD$

PORTNAME=	Tree-Suffix
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libstree library

LIB_DEPENDS=	libstree.so:${PORTSDIR}/textproc/libstree

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
