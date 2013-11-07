# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Bigtop
PORTVERSION=	0.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web application data language processor

BUILD_DEPENDS=	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-IO-Prompt>=0:${PORTSDIR}/devel/p5-IO-Prompt \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Gantry>=3.38:${PORTSDIR}/www/p5-Gantry \
		p5-Inline>=0.40:${PORTSDIR}/devel/p5-Inline \
		p5-Inline-TT>=0.06:${PORTSDIR}/devel/p5-Inline-TT \
		p5-Template-Toolkit>=2.0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-HTTP-Server-Simple>0.27:${PORTSDIR}/www/p5-HTTP-Server-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS=	</dev/null

.include <bsd.port.mk>
