# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	gkx86info2
PORTVERSION=	0.0.2
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	http://anchois.free.fr/ \
		http://depot.fsck.ch/mirror/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM2 plugin that simply prints the current clock speed

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

ONLY_FOR_ARCHS=	i386 amd64
USES=		gnome pkgconfig
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/gkx86info${PORTVERSION}
PLUGINDIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -fPIC -o MHz.o -c MHz.c
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -fPIC \
		`pkg-config gtk+-2.0 --cflags` -c gkx86info.c
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -shared \
		 -o ${PORTNAME}.so MHz.o gkx86info.o

do-install:
	@${MKDIR} ${PLUGINDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${PLUGINDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
