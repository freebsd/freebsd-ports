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
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gtk20
SLAVE_TRANS=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TARGETS = .cli|#TARGETS = .cli|g' \
		${WRKSRC}/mk/default.mk

.include "${MASTERDIR}/Makefile"
