# New ports collection makefile for:	linux-mozillafirebird-el
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

CATEGORIES=		www linux
MASTER_SITE_SUBDIR=	firebird/releases/${PORTVERSION}/contrib-localized
PKGNAMEPREFIX=		el-linux-
DISTNAME=		MozillaFirebird-${PORTVERSION}-i686-pc-linux-gnu-elGR
COMMENT=		Firebird Web browser:  Greek Linux/i386 version

PLIST_FILES=		lib/el-linux-mozillafirebird/chrome/el-unix.jar \
			lib/el-linux-mozillafirebird/chrome/el-win.jar \
			lib/el-linux-mozillafirebird/chrome/el-gr.jar \
			lib/el-linux-mozillafirebird/chrome/el-mac.jar \
			lib/el-linux-mozillafirebird/install.log \
			lib/el-linux-mozillafirebird/registry

MASTERDIR=		${.CURDIR}/../../www/linux-mozillafirebird
.include "${MASTERDIR}/Makefile"
