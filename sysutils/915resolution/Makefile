# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	915resolution
PORTVERSION=	0.5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/cy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resolution tool for Intel i915 video cards

USE_RC_SUBR=	915resolution

PLIST_FILES=	sbin/915resolution
PORTDOCS=	README.txt LICENSE.txt chipset_info.txt changes.log

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/915resolution.c -o ${WRKSRC}/915resolution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/915resolution ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
