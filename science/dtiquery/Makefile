############################################################################
# New ports collection Makefile for:   DTI-Query
# Date created:        10 July 2006
# Whom:                Jason W. Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#
############################################################################

PORTNAME=	dtiquery
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	science biology
MASTER_SITES=	http://graphics.stanford.edu/projects/dti/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Stanford DTI Visualization tool

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:${PORTSDIR}/devel/tnt \
		${LOCALBASE}/include/tnt/jama_cholesky.h:${PORTSDIR}/math/jama \
		${LOCALBASE}/lib/libRAPID.a:${PORTSDIR}/math/rapid
EXTRACT_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos
LIB_DEPENDS=	wx_gtk2_core-2.8.0:${PORTSDIR}/x11-toolkits/wxgtk28 \
		vtkCommon.5:${PORTSDIR}/math/vtk5

CONFLICTS=	dtiquery-1.0*

RESTRICTED=	Must register to download at http://graphics.stanford.edu/projects/dti/

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_GMAKE=	yes

PLIST_FILES=	bin/dtiquery \
		bin/dtiprecompute_cmd \
		bin/dtiprecompute_gui

ALL_TARGET=

MAN1=		dtiquery.1 \
		dtiprecompute_cmd.1 \
		dtiprecompute_gui.1

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
IGNORE=	you must manually fetch ${DISTNAME}.tar.gz from http://graphics.stanford.edu/projects/dti/, place it in ${DISTDIR}, and then run make again
.endif

post-extract:
	dos2unix ${WRKSRC}/*/Makefile ${WRKSRC}/Makefile*
	${REINPLACE_CMD} "s/zlib-1.2.2 RAPID201//g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DTIQuery/dtiquery ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/precompute/dtiprecompute_cmd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/precompute/dtiprecompute_gui ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/dtiquery.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${FILESDIR}/dtiquery.1 ${MAN1PREFIX}/man/man1/dtiprecompute_cmd.1
	${INSTALL_MAN} ${FILESDIR}/dtiquery.1 ${MAN1PREFIX}/man/man1/dtiprecompute_gui.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
