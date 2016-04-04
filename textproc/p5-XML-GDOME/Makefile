# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-GDOME
PORTVERSION=	0.86
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module that provides the DOM Level 2 Core API for XML documents

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:textproc/p5-XML-SAX
LIB_DEPENDS=	libgdome.so:textproc/gdome2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
