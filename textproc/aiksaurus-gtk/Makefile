# New ports collection makefile for:	aiksaurus-gtk
# Date created:				23 July 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	textproc deskutils
PKGNAMESUFFIX=	-gtk

COMMENT=	A GTK+2 front-end for Aiksaurus, a thesaurus

LIB_DEPENDS=	Aiksaurus-1.2.0:${PORTSDIR}/textproc/aiksaurus

MASTERDIR=	${.CURDIR}/../aiksaurus
PKGDIR=		${.CURDIR}

USE_GNOME=	gnomehack gtk20
USE_REINPLACE=	yes
CONFIGURE_ARGS=--with-gtk

pre-install:
	@${REINPLACE_CMD} -e 's|base [$$][(]GTKSRCDIR[)] data|$$(GTKSRCDIR)|g' \
		${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
