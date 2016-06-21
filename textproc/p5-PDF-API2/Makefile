# Created by: ijliao
# $FreeBSD$

PORTNAME=	PDF-API2
PORTVERSION=	2.028
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Facilitates the creation and modification of PDF files

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Font-TTF>=0:x11-fonts/p5-Font-TTF
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
