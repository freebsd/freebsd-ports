# $FreeBSD$

PORTNAME=	Senna
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Embeddable Fulltext Search Engine

LICENSE=	LGPL21

BUILD_DEPENDS=	senna-cfg:textproc/senna
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS+=</dev/null
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
