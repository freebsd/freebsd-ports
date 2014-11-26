# Created by: clsung
# $FreeBSD$

PORTNAME=	Tree-Suffix
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the libstree library

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:${PORTSDIR}/devel/p5-Devel-CheckLib
LIB_DEPENDS=	libstree.so:${PORTSDIR}/textproc/libstree

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${RM} -rf ${WRKSRC}/inc

.include <bsd.port.mk>
