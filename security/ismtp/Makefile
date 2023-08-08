PORTNAME=	ismtp
DISTVERSION=	g20190921
CATEGORIES=	security

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Test for SMTP user enumeration, internal spoofing, and relay
WWW=		https://github.com/altjx/ipwn/tree/master/iSMTP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/iSMTP/LICENSE.md

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	altjx
GH_PROJECT=	ipwn
GH_TAGNAME=	18198ad887c2d7e59c05b3f860d92e56f54d9144

SHEBANG_FILES=	${WRKSRC}/iSMTP/iSMTP.py

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ismtp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/iSMTP/iSMTP.py  ${STAGEDIR}${PREFIX}/bin/ismtp

.include <bsd.port.mk>
