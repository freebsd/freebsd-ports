# New ports collection makefile for:	JDE's Binder
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	binder
PORTVERSION=	1.3
CATEGORIES=	x11-fm windowmaker tkstep80
MASTER_SITES=	http://www.aaa-int.or.jp/~jfactory/JDE/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	Binder-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file manager on X window with TkStep

RUN_DEPENDS=	${RUN_DEP_LIST}
LIB_DEPENDS=	${LIB_DEP_LIST}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
REINPLACE_ARGS=
SCRIPTS_ENV=	LANG=C LN=${LN} REINPLACE_CMD="${REINPLACE_CMD}" \
		LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}
PLIST_SUB=	PIXMAP_PATH=${PIXMAPPATH:S@^${PREFIX}/@@}

TKSTEPVERSION=	8.0
PIXMAPPATH?=	${PREFIX}/share/WindowMaker/Pixmaps
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEP_LIST=	img.1:${PORTSDIR}/graphics/libimg

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${MKDIR} ${PIXMAPPATH}
	${INSTALL_DATA} ${PREFIX}/JDE/Binder/docs/Binder.xpm \
			${PREFIX}/JDE/Binder/misc/Mounter/DiskHardDrive.xpm \
			${PIXMAPPATH}

.include <bsd.port.mk>
