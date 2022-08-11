PORTNAME=	postsrsd
PORTVERSION=	1.10
CATEGORIES=	mail

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Postfix Sender Rewriting Scheme daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cmake cpe pkgconfig
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	roehling
USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS=	--no-warn-unused-cli \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

PLIST_FILES=	man/man8/postsrsd.8.gz \
		sbin/postsrsd

PORTDOCS=	README.md README_UPGRADE.md main.cf.ex

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	ENABLE_DOCS

.include <bsd.port.mk>
