# New ports collection makefile for:	uplog
# Date created:				16.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	uplog
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://www.nerdlabs.org/downloads/${PORTNAME}/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	UDP-based ping programm

USE_SIZE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e \
	's|#include <malloc.h>||g' \
		${WRKSRC}/${PORTNAME}.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
