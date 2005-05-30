# New ports collection makefile for:	xmms-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-bluecurve-theme

COMMENT=	The Bluecurve XMMS skin

RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

MASTERDIR=	${.CURDIR}/../bluecurve-themes

NO_BUILD=	yes

SKIN=		Bluecurve-xmms.zip
PLIST_FILES=	share/xmms/Skins/${SKIN}

do-install:
	${MKDIR} ${PREFIX}/share/xmms/Skins
	${INSTALL_DATA} ${WRKSRC}/art/xmms/${SKIN} ${PREFIX}/share/xmms/Skins

.include "${MASTERDIR}/Makefile"
