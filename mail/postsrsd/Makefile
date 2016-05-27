# Created by: Krzysztof Stryjek <ports@bsdserwis.com>
# $FreeBSD$

PORTNAME=	postsrsd
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Postfix Sender Rewriting Scheme daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man \
		base64:converters/base64
RUN_DEPENDS=	base64:converters/base64

USE_GITHUB=	yes
GH_ACCOUNT=	roehling

USES=		cmake pkgconfig
CMAKE_ARGS=	--no-warn-unused-cli \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	README.md main.cf.ex README_UPGRADE.md

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_ON=	-DENABLE_DOCS:STRING="ON"

PLIST_FILES=	sbin/postsrsd man/man8/postsrsd.8.gz etc/postsrsd.secret

.include <bsd.port.mk>
