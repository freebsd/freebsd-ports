# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	xpvm
PORTVERSION=	1.2.5
PORTREVISION=	3
CATEGORIES=	net parallel
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	pvm3/xpvm
DISTNAME=	XPVM.src.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphical Console and Monitor for PVM

MAKE_JOBS_UNSAFE=	yes

USE_GCC=	yes
BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libtk84.so:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/xpvm
PVM_ROOT?=	${LOCALBASE}/lib/pvm
MAKE_ENV+=	PVM_ROOT=${PVM_ROOT} XPVM_ROOT=${WRKSRC}
SUB_FILES=	pkg-message

ALL_TARGET=	default

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If your PVM is not installed in the default directory,"
	@${ECHO_MSG} "please define PVM_ROOT=/path/to/your/pvm."
	@${ECHO_MSG}

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/malloc.h/stdlib.h/' \
	   src/xpvm.h tracer/trclib.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/FREEBSD/xpvm ${PREFIX}/bin
	${MKDIR} -m 755 ${DATADIR}
	for i in src/*.tcl ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DATADIR}; \
	done
	${MKDIR} -m 755 ${DATADIR}/src/xbm
	for i in src/xbm/* ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DATADIR}/src/xbm; \
	done
	${MKDIR} -m 755 ${DATADIR}/src/help
	for i in src/help/* ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DATADIR}/src/help; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
