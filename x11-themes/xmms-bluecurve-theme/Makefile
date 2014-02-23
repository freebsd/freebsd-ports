# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-bluecurve-theme
PORTREVISION=	2

COMMENT=	The Bluecurve XMMS skin

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		unzip:${PORTSDIR}/archivers/unzip

MASTERDIR=	${.CURDIR}/../bluecurve-themes

PREFIX=		${LOCALBASE}

NO_BUILD=	yes

SKIN=		Bluecurve-xmms.zip
PLIST_FILES=	share/xmms/Skins/${SKIN}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xmms/Skins
	${INSTALL_DATA} ${WRKSRC}/art/xmms/${SKIN} ${STAGEDIR}${PREFIX}/share/xmms/Skins

.include "${MASTERDIR}/Makefile"
