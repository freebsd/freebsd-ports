# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki
PORTVERSION=	0.27.0.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-i18n

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_TAGNAME=	5a4c5eb

### We can not go WITHOUT_NLS. Internationalization is needed
### even to use English language.
USES=		gettext-runtime gettext-tools gmake perl5
ALL_TARGET=	scan default

.include <bsd.port.mk>
