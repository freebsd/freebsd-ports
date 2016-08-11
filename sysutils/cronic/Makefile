# $FreeBSD$

PORTNAME=	cronic
PORTVERSION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://habilis.net/cronic/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	dharrigan@gmail.com
COMMENT=	Shell script that handles cron error detection

LICENSE=	CC0-1.0

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	${PORTNAME}-v${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
