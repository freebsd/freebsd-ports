# New ports collection makefile for:	JDE's SeizeDesktop
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seizedesktop
PORTVERSION=	0.1a
PORTREVISION=	3
CATEGORIES=	misc windowmaker tkstep80
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	SeizeDesktop-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A customizer of desktop screen environment

RUN_DEPENDS=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg-tkstep80

DEPRECATED=	development stalled for years, outdated, unmaintained
EXPIRATION_DATE=	2007-11-16

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
REINPLACE_ARGS=
TKSTEPVERSION=	8.0
SCRIPTS_ENV=	LANG=C LN=${LN} REINPLACE_CMD='${REINPLACE_CMD}' \
		LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}

.include <bsd.port.mk>
