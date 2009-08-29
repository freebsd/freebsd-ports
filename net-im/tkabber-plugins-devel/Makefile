# New ports collection makefile for:	tkabber-plugins
# Date created:				Wed Oct 17 19:09:46 MSD 2007
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	tkabber-plugins
PORTVERSION=	20090816
CATEGORIES=	net-im
MASTER_SITES=	http://wizard.volgograd.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	External Plugins for Tkabber

RUN_DEPENDS=	tkabber-devel>=0.11.1.a.20081023:${PORTSDIR}/net-im/tkabber-devel

USE_BZIP2=	yes

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

SUBDIRS=	aniemoticons attline bc browser checkers chess ctcomp \
		custom-urls cyrillize debug ejabberd floatingcontact \
		floatinglog georoster gmail iconsets jidlink latex mute \
		openurl osd poker presencecmd quiz quotelastmsg receipts \
		renju reversi singularity socials spy stripes tclchat \
		tkabber-khim traffic unixkeys whiteboard

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${SUBDIRS}" ${DATADIR})

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
