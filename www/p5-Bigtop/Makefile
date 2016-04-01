# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Bigtop
PORTVERSION=	0.38
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web application data language processor

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-General>=0:devel/p5-Config-General \
		p5-IO-Prompt>=0:devel/p5-IO-Prompt \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-JSON>=0:converters/p5-JSON \
		p5-Gantry>=3.38:www/p5-Gantry \
		p5-Inline>=0.40:devel/p5-Inline \
		p5-Inline-TT>=0.06:devel/p5-Inline-TT \
		p5-Template-Toolkit>=2.0:www/p5-Template-Toolkit \
		p5-HTTP-Server-Simple>0.27:www/p5-HTTP-Server-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ENV=	TENTMAKER_TEMPLATE_PATH=${STAGEDIR}${PREFIX}/share/TentMaker

.include <bsd.port.mk>
