# New ports collection makefile for:	tinypy
# Date created:		2009-02-26
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	tinypy
PORTVERSION=	1.1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A minimalist implementation of python in 64k of code

USE_PYTHON_BUILD=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_BUILD_TARGET=	linux
PYDISTUTILS_NOEGGINFO=		yes

PLIST_FILES=	bin/tinypy
PORTEXAMPLES=	*

OPTIONS=	PYGAME "Enable PyGame support (requires SDL)" off

.include <bsd.port.options.mk>

.if defined(WITH_PYGAME)
PYDISTUTILS_BUILD_TARGET+=	pygame
USE_SDL=	sdl
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O.||; s|gcc $$WFLAGS|${CC} ${CFLAGS} -std=c89 -Wall|' \
		${WRKSRC}/setup.py

do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/tinypy ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES) && defined(WITH_PYGAME)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/julia.py ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
