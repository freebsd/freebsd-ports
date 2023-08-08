PORTNAME=	Template-Plugin-Gettext
PORTVERSION=	1.0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Gettext support for the Template Toolkit version 2
WWW=		https://metacpan.org/release/Template-Plugin-Gettext

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Locale-XGettext>=0.7:devel/p5-Locale-XGettext \
		p5-Locale-libintl>=1.30:devel/p5-Locale-libintl \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
