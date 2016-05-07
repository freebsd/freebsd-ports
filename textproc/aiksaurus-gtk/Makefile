# $FreeBSD$

PORTREVISION=	12
CATEGORIES=	textproc deskutils
PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+2 front-end for Aiksaurus, a thesaurus

LIB_DEPENDS=	libAiksaurus.so:textproc/aiksaurus

MASTERDIR=	${.CURDIR}/../aiksaurus
PKGDIR=		${.CURDIR}

USE_GNOME=	gtk20
CONFIGURE_ARGS=--with-gtk

pre-install:
	@${REINPLACE_CMD} -e 's|base [$$][(]GTKSRCDIR[)] data|$$(GTKSRCDIR)|g' \
		${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
