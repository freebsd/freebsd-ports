# New ports collection makefile for:	DFileServer
# Date created:				8 September 2005
# Whom:					Dash|RD
#
# $FreeBSD$
#

PORTNAME=	DFileServer
PORTVERSION=	1.1.3
CATEGORIES=	www
MASTER_SITES=	http://harpy.soarwitheagles.net/~dashy/

MAINTAINER=	dashevil@gmail.com
COMMENT=	A compact webserver designed to make sharing files easy

PLIST_FILES=	bin/dfileserver

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV=	CXX=${CXX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

post-patch:
	${REINPLACE_CMD} 's,g++,${CXX},;s,$$GCCFLAGS,${CXXFLAGS},; \
		s,strip,${STRIP_CMD},' ${WRKSRC}/build.sh

do-build:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ./build.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DFileServer.x86 ${PREFIX}/bin/dfileserver

.include <bsd.port.post.mk>
