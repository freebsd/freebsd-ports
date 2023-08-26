PORTNAME=	915resolution
PORTVERSION=	0.5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/cy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resolution tool for Intel i915 video cards
WWW=		http://915resolution.mango-lang.org/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 i386

USE_RC_SUBR=	915resolution

PLIST_FILES=	sbin/915resolution
PORTDOCS=	README.txt changes.log chipset_info.txt

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/915resolution.c -o ${WRKSRC}/915resolution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/915resolution ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
