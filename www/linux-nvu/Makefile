# New ports collection makefile for:	linux-nvu
# Date created:				2004-05-10
# Whom:					Ilya Khamushkin
#
# $FreeBSD$
#

PORTNAME=	nvu
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	www linux
MASTER_SITES=	http://cvs.nvu.com/download/
PKGNAMEPREFIX=	linux-
DISTFILES=	${DISTNAME}-pc-linux-gnu${EXTRACT_SUFX}

MAINTAINER=	ilya@space.rootshell.ru
COMMENT=	A complete Web Authoring System

RUN_DEPENDS=	\
	${LINUXBASE}/usr/lib/libgobject-2.0.so.0:${PORTSDIR}/devel/linux-glib2 \
	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2 \
	${LINUXBASE}/usr/lib/libatk-1.0.so.0:${PORTSDIR}/accessibility/linux-atk \
	${LINUXBASE}/usr/lib/libpango-1.0.so.0:${PORTSDIR}/x11-toolkits/linux-pango \
	${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=		i386
USE_X_PREFIX=		yes
NVULIB_DIR=		lib/${UNIQUENAME}
INSTALL_DIR=		${PREFIX}/${NVULIB_DIR}
PLIST_SUB=		NVULIB_DIR=${NVULIB_DIR}

do-install:
	@${MKDIR} ${INSTALL_DIR}
	@cd ${WRKSRC} && ${FIND} * | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${INSTALL_DIR}
	@${LN} -s ${INSTALL_DIR}/${PORTNAME} \
		${PREFIX}/bin/${UNIQUENAME}

.include <bsd.port.mk>
