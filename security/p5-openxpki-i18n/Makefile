# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki
PORTVERSION=	0.26.1.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-i18n
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9bd1fea

### We can not go WITHOUT_NLS. Internationalization is needed
### even to use English language.
USES=		gettext-runtime gettext-tools gmake perl5
ALL_TARGET=	scan default

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/core/i18n

.include <bsd.port.mk>
