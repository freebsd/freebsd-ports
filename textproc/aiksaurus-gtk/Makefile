# $FreeBSD$

PORTREVISION=	12
CATEGORIES=	textproc deskutils
PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+2 front-end for Aiksaurus, a thesaurus

BROKEN=		does not link against GTK2 on FreeBSD 10+
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2017-01-15

LIB_DEPENDS=	libAiksaurus.so:textproc/aiksaurus

MASTERDIR=	${.CURDIR}/../aiksaurus
PKGDIR=		${.CURDIR}

USE_GNOME=	gtk20
CONFIGURE_ARGS=--with-gtk

pre-install:
	@${REINPLACE_CMD} -e 's|base [$$][(]GTKSRCDIR[)] data|$$(GTKSRCDIR)|g' \
		${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
