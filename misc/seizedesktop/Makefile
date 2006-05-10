# New ports collection makefile for:	JDE's SeizeDesktop
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seizedesktop
PORTVERSION=	0.1a
CATEGORIES=	misc windowmaker tkstep80
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	SeizeDesktop-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A customizer of desktop screen environment

RUN_DEPENDS=	${RUN_DEP_LIST}
LIB_DEPENDS=	${LIB_DEP_LIST}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
REINPLACE_ARGS=
SCRIPTS_ENV=	LANG=C LN=${LN} REINPLACE_CMD='${REINPLACE_CMD}' \
		LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}

TKSTEPVERSION=	8.0
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEP_LIST=	img.1:${PORTSDIR}/graphics/libimg

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}

.include <bsd.port.mk>
