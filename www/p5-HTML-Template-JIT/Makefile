# Created by: alex@kapranoff.ru
# $FreeBSD$

PORTNAME=	HTML-Template-JIT
PORTVERSION=	0.05
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to compile HTML Templates with Inline::C

LICENSE=	ARTPERL10

BUILD_DEPENDS=	p5-HTML-Template>=2.8:www/p5-HTML-Template \
		p5-Inline>=0.43:devel/p5-Inline \
		p5-Inline-C>=0:devel/p5-Inline-C
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/indent -kr/indent/' ${WRKSRC}/JIT/Compiler.pm

.include <bsd.port.mk>
