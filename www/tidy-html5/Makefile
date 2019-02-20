# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	tidy-html5
PORTVERSION=	5.6.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tidy tidies HTML and XML documents

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	htacg

USES=		cmake gnome
USE_GNOME=	libxslt
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIB:BOOL=ON	\
		-DTIDY_CONSOLE_SHARED:BOOL=ON

PLIST_SUB=	VER=${PORTVERSION}

post-install:
	# To avoid conflict ATM - to be removed later
	${MV} ${STAGEDIR}${PREFIX}/bin/tidy ${STAGEDIR}${PREFIX}/bin/tidy5
	${MV} ${STAGEDIR}${PREFIX}/lib/libtidy.so ${STAGEDIR}${PREFIX}/lib/libtidy5.so
	${MV} ${STAGEDIR}${MANPREFIX}/man/man1/tidy.1 ${STAGEDIR}${MANPREFIX}/man/man1/tidy5.1

.include <bsd.port.mk>
