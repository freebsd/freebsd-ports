PORTNAME=	DFileServer
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/ \
		http://harpy.soarwitheagles.net/~dashy/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Compact webserver designed to make sharing files easy

LICENSE=	BSD3CLAUSE

USES=	dos2unix

PLIST_FILES=	bin/dfileserver

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's,g++,${CXX},;s,$$GCCFLAGS,${CXXFLAGS},; \
		s,strip,${STRIP_CMD},' ${WRKSRC}/build.sh

do-build:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ./build.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DFileServer.x86 ${STAGEDIR}${PREFIX}/bin/dfileserver

.include <bsd.port.mk>
