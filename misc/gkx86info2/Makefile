# New ports collection makefile for:	gkx86info2
# Date created:		Tue Apr 27 14:15:53 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	gkx86info2
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://anchois.free.fr/ \
		http://depot.fsck.ch/mirror/distfiles/

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin that simply prints the current clock speed

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/gkx86info${PORTVERSION}

do-build:
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -o MHz.o -c MHz.c
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -fPIC \
		`pkg-config gtk+-2.0 --cflags` -c gkx86info.c
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -shared \
		 -o ${PORTNAME}.so MHz.o gkx86info.o

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm2/plugins/

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
