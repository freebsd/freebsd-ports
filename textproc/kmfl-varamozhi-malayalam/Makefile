# New ports collection makefile for:	scim-kmfl-varamozhi-malayalam
# Date created:		10 October 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	scim-kmfl-varamozhi-malayalam
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/varamozhi/2%20Mozhi%20Keyman%20-%20Input%20Method/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/kmfl/
DISTNAME=	mozhi_${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM KMFL IMEngine Malayalam keyboard according to the Mozhi scheme

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

USE_DOS2UNIX=	mozhi_1.1.0.kmn
NO_BUILD=	yes
USE_ZIP=	yes

SCIM_KMFL_DIR=	share/scim/kmfl
SCIM_KMFL_ICONS_DIR=	share/scim/kmfl/icons

PLIST_FILES=	${SCIM_KMFL_DIR}/mozhi_1.1.0.kmn \
		${SCIM_KMFL_ICONS_DIR}/mozhi.bmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${SCIM_KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${LOCALBASE}/${SCIM_KMFL_ICONS_DIR}

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Malayalam\" in your SCIM menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
	@${ECHO_MSG}
	@${ECHO_MSG} "  At the moment, this keyboard has no downloadable"
	@${ECHO_MSG} "  documentation. For the details on the Mozhi scheme,"
	@${ECHO_MSG} "  please see the Project's homepage, especially"
	@${ECHO_MSG} "  https://sites.google.com/site/cibu/mozhi."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
