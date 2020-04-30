# Created by: Krzysztof Stryjek <ports@bsdserwis.com>
# $FreeBSD$

PORTNAME=	postsrsd
PORTVERSION=	1.6
CATEGORIES=	mail

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Postfix Sender Rewriting Scheme daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	roehling

CMAKE_ARGS=	--no-warn-unused-cli \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	README.md main.cf.ex README_UPGRADE.md

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	ENABLE_DOCS

PLIST_FILES=	sbin/postsrsd man/man8/postsrsd.8.gz

.include <bsd.port.mk>
