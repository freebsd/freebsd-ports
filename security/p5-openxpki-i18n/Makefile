# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openxpki-i18n
PORTVERSION=	0.19.0.1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-
DISTNAME=	openxpki-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: i18n tools

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-openxpki>=0.14:${PORTSDIR}/security/p5-openxpki
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	openxpki
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9d772a8

### We can not go WITHOUT_NLS. Internationalization is needed
### even to use English language.
USES=		gettext gmake perl5
ALL_TARGET=	scan default

MAKE_JOBS_UNSAFE=	yes

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/core/i18n

.include <bsd.port.mk>
