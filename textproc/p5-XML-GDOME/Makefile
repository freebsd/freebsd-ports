# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-GDOME
PORTVERSION=	0.86
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that provides the DOM Level 2 Core API for XML documents

LIB_DEPENDS=	libgdome.so:${PORTSDIR}/textproc/gdome2
BUILD_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
