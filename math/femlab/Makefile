# New ports collection makefile for:	femlab
# Date created:		19 June 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	femlab
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	math science
# mastersite disappeared in April 2000
MASTER_SITES=	# ftp://ftp.md.chalmers.se/pub/Femlab/
DISTFILES=	femlab-2d-v${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive program for solving partial differential equations in 2D

BUILD_DEPENDS=	${LOCALBASE}/lib/libsx.a:${PORTSDIR}/x11/libsx \
		imake:${PORTSDIR}/devel/imake

USE_XORG=	xaw
USE_FORTRAN=	yes

FEMLAB_HOME=	${PREFIX}/lib/X11/femlab

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
	${WRKSRC}/source/graph.c ${WRKSRC}/source/y.tab.c \
	${WRKSRC}/source/newdata.c ${WRKSRC}/source/post.c \
	${WRKSRC}/source/kraftwerk.c ${WRKSRC}/source/list.c \
	${WRKSRC}/include/xv.h ${WRKSRC}/fsource/y.tab.c

do-install:
	${MKDIR} ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/femlab ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsource/meshgen ${FEMLAB_HOME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsource/poisson ${FEMLAB_HOME}/bin
	${MKDIR} ${FEMLAB_HOME}/config
	${INSTALL_DATA} ${WRKSRC}/config/modules ${FEMLAB_HOME}/config
	${SED} -e "s|@@FEMLAB_HOME@@|${FEMLAB_HOME}|" <${FILESDIR}/femlab.sh >${PREFIX}/bin/femlab
	${CHMOD} +x ${PREFIX}/bin/femlab

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/femlab
	@${INSTALL_DATA} ${WRKSRC}/examples/*.fem ${PREFIX}/share/examples/femlab
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/manual.dvi ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/manual.ps  ${DOCSDIR}
.endif

.include <bsd.port.mk>
