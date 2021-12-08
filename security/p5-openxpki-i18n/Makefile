# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>

PORTNAME=	openxpki
DISTVERSIONPREFIX=	v
DISTVERSION=	3.16.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-i18n

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

# We cannot go without NLS. Internationalization is needed even for English.
USES=		gettext-runtime gettext-tools gmake perl5

USE_GITHUB=	yes

ALL_TARGET=	scan default
NO_ARCH=	yes
# stay with stable versions only:
PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	core/i18n

.include <bsd.port.mk>
