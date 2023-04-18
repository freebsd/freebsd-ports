PORTNAME=	chatgpt-shell-cli
DISTVERSION=	g20230411
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Shell script to use OpenAI's ChatGPT and DALL-E from the terminal
WWW=		https://github.com/0xacx/chatGPT-shell-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		jq:textproc/jq \
		xdg-open:devel/xdg-utils

USES=		magick:run

USE_GITHUB=	yes
GH_ACCOUNT=	0xacx
GH_PROJECT=	chatGPT-shell-cli
GH_TAGNAME=	42d82b9

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	chatgpt

post-patch:
		  ${REINPLACE_CMD} 's/open \("$${image_url}"\)/xdg-open \1/g' ${WRKSRC}/chatgpt.sh

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/chatgpt.sh ${PREFIX}/bin/chatgpt

.include <bsd.port.mk>
