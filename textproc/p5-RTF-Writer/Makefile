# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	RTF-Writer
PORTVERSION=	1.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for generating documents in Rich Text Format

BUILD_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	RTF::Writer.3 \
	RTF::Writer::TableRowDecl.3 \
	RTF::Cookbook.3

.include <bsd.port.mk>
