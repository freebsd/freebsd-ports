PORTNAME=	lscpu
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Display information about the CPU architecture
WWW=		https://github.com/NanXiao/lscpu

LICENSE=	BSD3CLAUSE

PATCH_SITES+=	https://github.com/NanXiao/lscpu/commit/
PATCHFILES+=	6243acc4393f32a0a52d8eeec35081ebb3027cfe.patch:-p1

PATCH_SITES+=   https://github.com/LaurentChardon/lscpu/commit/
PATCHFILES+=    e955a62428a3e226ec7cfc011e450c7240eea24f.patch:-p1

USE_GITHUB=	yes
GH_ACCOUNT=	NanXiao

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
