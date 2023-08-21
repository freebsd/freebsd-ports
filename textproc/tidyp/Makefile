PORTNAME=	tidyp
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	textproc www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and program to validate and fix HTML
WWW=		https://github.com/petdance/tidyp

LICENSE=	HTML_TIDY
LICENSE_NAME=	HTML Tidy License
LICENSE_FILE=	${WRKSRC}/htmldoc/license.html
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		autoreconf libtool

CONFIGURE_ARGS=	--enable-asian --enable-utf16
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	petdance
USE_GITHUB=	yes

OPTIONS_DEFINE=	ACCESS DEBUG
ACCESS_DESC=	Accessibility checks

ACCESS_CONFIGURE_ENABLE=access
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
