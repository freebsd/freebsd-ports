# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	xpvm
PORTVERSION=	1.2.5
PORTREVISION=	4
CATEGORIES=	net parallel
MASTER_SITES=	NL/pvm3/xpvm
DISTNAME=	XPVM.src.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical console and monitor for PVM

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:net/pvm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		tk:84 tar:tgz
USE_GCC=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/xpvm
PVM_ROOT?=	${LOCALBASE}/lib/pvm
MAKE_ENV+=	PVM_ROOT=${PVM_ROOT} XPVM_ROOT=${WRKSRC}
SUB_FILES=	pkg-message

ALL_TARGET=	default

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If your PVM is not installed in the default directory,"
	@${ECHO_MSG} "please define PVM_ROOT=/path/to/your/pvm."
	@${ECHO_MSG}

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/malloc.h/stdlib.h/' \
	   src/xpvm.h tracer/trclib.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/FREEBSD/xpvm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} -m 755 ${STAGEDIR}${DATADIR}/src/xbm
	@${MKDIR} -m 755 ${STAGEDIR}${DATADIR}/src/help
	${INSTALL_DATA} ${WRKSRC}/src/*.tcl ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/xbm/* ${STAGEDIR}${DATADIR}/src/xbm
	${INSTALL_DATA} ${WRKSRC}/src/help/* ${STAGEDIR}${DATADIR}/src/help

.include <bsd.port.mk>
