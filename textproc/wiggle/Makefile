PORTNAME=	wiggle
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://neil.brown.name/wiggle/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Apply rejected patches and perform word-wise diffs

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake groff
USE_GITHUB=	yes
GH_TUPLE=	neilbrown:${PORTNAME}:v${PORTVERSION}

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I. -Wall -Wstrict-prototypes -Wextra -Wno-unused-parameter"

pre-patch:
		${REINPLACE_CMD} -Ee 's,\./dotest,bash ./dotest,' ${WRKSRC}/Makefile
		${REINPLACE_CMD} -Ee 's|#include.*<endian.h>|#include <sys/endian.h>|' ${WRKSRC}/config.h

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/wiggle ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/wiggle.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
