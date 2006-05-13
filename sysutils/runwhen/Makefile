# New ports collection makefile for:	runwhen
# Date created:		2003-10-31
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	runwhen
PORTVERSION=	2003.10.31
CATEGORIES=	sysutils
MASTER_SITES=	http://code.dogmap.org./${PORTNAME}/releases/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	Tools for running commands at particular times

BUILD_DEPENDS=	${LOCALBASE}/include/skalibs:${PORTSDIR}/devel/skalibs

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
ALL_TARGET=	default

DOCS=		src/CHANGES src/TODO package/README

post-patch:
	@${REINPLACE_CMD} -e 's!gcc -O2!${CC} ${CFLAGS}!' \
		${WRKSRC}/conf-compile/host_compile.sh

do-configure:
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-compile/package_home
	${ECHO_CMD} ${LOCALBASE} > ${WRKSRC}/conf-compile/depend_skalibs

do-build:
	cd ${WRKSRC} && package/compile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
