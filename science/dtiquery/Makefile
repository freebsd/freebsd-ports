# Created by: Jason W. Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	dtiquery
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	science biology
MASTER_SITES=	http://graphics.stanford.edu/projects/dti/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stanford DTI Visualization tool

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:${PORTSDIR}/devel/tnt \
		${LOCALBASE}/include/tnt/jama_cholesky.h:${PORTSDIR}/math/jama \
		${LOCALBASE}/lib/libRAPID.a:${PORTSDIR}/math/rapid
EXTRACT_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos
LIB_DEPENDS=	libwx_gtk2_core-2.8.so:${PORTSDIR}/x11-toolkits/wxgtk28 \
		libvtkCommon.so:${PORTSDIR}/math/vtk5

CONFLICTS=	dtiquery-1.0*

RESTRICTED=	Must register to download at http://graphics.stanford.edu/projects/dti/

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		gmake

PLIST_FILES=	bin/dtiquery \
		bin/dtiprecompute_cmd \
		bin/dtiprecompute_gui

ALL_TARGET=

MAN1=		dtiquery.1 \
		dtiprecompute_cmd.1 \
		dtiprecompute_gui.1

NO_STAGE=	yes
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
