# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmfl-varamozhi-malayalam
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/varamozhi/2%20Mozhi%20Keyman%20-%20Input%20Method/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	mozhi_${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	KMFL Malayalam keyboard according to the Mozhi scheme

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp

USES=		dos2unix zip
DOS2UNIX_FILES=	mozhi_1.1.0.kmn
NO_BUILD=	yes

KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

PLIST_FILES=	${KMFL_DIR}/mozhi_1.1.0.kmn \
		${KMFL_ICONS_DIR}/mozhi.bmp
PLIST_DIRSTRY=	${KMFL_ICONS_DIR} \
		${KMFL_DIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${LOCALBASE}/${KMFL_DIR} ${LOCALBASE}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${LOCALBASE}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${LOCALBASE}/${KMFL_ICONS_DIR}

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "  You should now have the new keyboard in the section"
	@${ECHO_MSG} "  \"Malayalam\" in your SCIM/IBus menu. If you don't see it,"
	@${ECHO_MSG} "  restart X."
	@${ECHO_MSG}
	@${ECHO_MSG} "  At the moment, this keyboard has no downloadable"
	@${ECHO_MSG} "  documentation. For the details on the Mozhi scheme,"
	@${ECHO_MSG} "  please see the Project's homepage, especially"
	@${ECHO_MSG} "  https://sites.google.com/site/cibu/mozhi."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
