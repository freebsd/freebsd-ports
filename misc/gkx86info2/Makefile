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

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

ONLY_FOR_ARCHS=	i386 amd64
USES=		pkgconfig
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/gkx86info${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -fPIC -o MHz.o -c MHz.c
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -fPIC \
		`pkg-config gtk+-2.0 --cflags` -c gkx86info.c
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -shared \
		 -o ${PORTNAME}.so MHz.o gkx86info.o

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm2/plugins/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
