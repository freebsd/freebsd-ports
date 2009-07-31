# New ports collection makefile for:	gkx86info
# Date created:		Thu Aug  8 01:49:15 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkx86info
PORTVERSION=	0.0.2
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin that simply prints the current clock speed

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

ONLY_FOR_ARCHS=	i386
USE_GNOME=	gtk12 imlib

PLIST_FILES=	libexec/gkrellm/plugins/gkx86info.so
.ifndef(NOPORTDOCS)
PORTDOCS=	COPYING README
.endif

do-build:
	@cd ${WRKSRC} && eval ${CC} ${CFLAGS} -o MHz.o -c MHz.c
	@cd ${WRKSRC} && eval ${CC} -fPIC ${CFLAGS} \
		`${GTK_CONFIG} --cflags` \
		`${IMLIB_CONFIG} --cflags-gdk` -c gkx86info.c
	@cd ${WRKSRC} && eval ${CC} -shared ${CFLAGS} ${LDFLAGS} \
		-o ${PORTNAME}.so MHz.o gkx86info.o

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm/plugins/

.include <bsd.port.mk>
