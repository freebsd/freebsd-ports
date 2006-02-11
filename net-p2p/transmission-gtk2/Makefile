# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gtk2

COMMENT=	A free BitTorrent client written from scratch in C with GTK+2

MASTERDIR=	${.CURDIR}/../transmission

USE_GNOME=	gtk20
SLAVE_PORT=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--gettext-prefix=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	bin/transmission-gtk

do-install: docsfiles
	${INSTALL_PROGRAM} ${WRKSRC}/gtk/transmission-gtk ${PREFIX}/bin/

.include "${MASTERDIR}/Makefile"
