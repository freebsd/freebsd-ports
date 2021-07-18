# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>

PORTNAME=	openxpki
PORTVERSION=	3.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-i18n

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

### We can not go without NLS. Internationalization is needed even for English
USES=		gettext-runtime gettext-tools gmake perl5

USE_GITHUB=	yes

ALL_TARGET=	scan default
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even # stay with stable versions only

WRKSRC_SUBDIR=	core/i18n

.include <bsd.port.mk>
