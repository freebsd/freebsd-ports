# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Pod-ProjectDocs
PORTVERSION=	0.48
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates CPAN like pod pages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-JSON>=2.04:converters/p5-JSON \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502400
BUILD_DEPENDS+=	p5-Pod-Simple>=3.31:textproc/p5-Pod-Simple
RUN_DEPENDS+=	p5-Pod-Simple>=3.31:textproc/p5-Pod-Simple
.endif

.include <bsd.port.post.mk>
