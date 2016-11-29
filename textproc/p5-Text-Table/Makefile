# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	Text-Table
PORTVERSION=	1.132
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Organize Data in Tables

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Text-Aligner>=0:textproc/p5-Text-Aligner
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
