# New ports collection makefile for:	xpvm
# Date created:				02 April 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	xpvm
PORTVERSION=	1.2.5
CATEGORIES=	net parallel
MASTER_SITES=	http://www.netlib.org/pvm3/xpvm/
DISTNAME=	XPVM.src.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphical Console and Monitor for PVM

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/xpvm
PVM_ROOT?=	${LOCALBASE}/lib/pvm
MAKE_ENV+=	PVM_ROOT=${PVM_ROOT} XPVM_ROOT=${WRKSRC}
PKGMESSAGE=	${WRKDIR}/pkg-message

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
	@${SED} -e 's,%%DATADIR%%,${DATADIR},' \
	                  -e 's,%%LOCALBASE%%,${LOCALBASE},' \
	                  <${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
