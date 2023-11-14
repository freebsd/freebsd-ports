PORTNAME=	minipro
PORTVERSION=	0.5
CATEGORIES=	sysutils

MAINTAINER=	bofh@freebsd.org
COMMENT=	CLI for MiniPRO TL866xx chip programmers
WWW=		https://gitlab.com/DavidGriffith/minipro

LICENSE=	GPLv3

BUILD_DEPENDS=	gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake pkgconfig shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	DavidGriffith
GL_PROJECT=	${PORTNAME}
GL_TAGNAME=	8be592c954264afdc3a2cb596ee45517cc5dc621

SHEBANG_FILES=	miniprohex

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_FILES=	bin/minipro \
		bin/miniprohex \
		man/man1/minipro.1.gz \
		share/minipro/infoic.xml

post-install:
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/minipro.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
