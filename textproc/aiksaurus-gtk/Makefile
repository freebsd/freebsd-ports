# $FreeBSD$

PORTREVISION=	12
CATEGORIES=	textproc deskutils
PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+2 front-end for Aiksaurus, a thesaurus

LIB_DEPENDS=	libAiksaurus.so:${PORTSDIR}/textproc/aiksaurus

MASTERDIR=	${.CURDIR}/../aiksaurus
PKGDIR=		${.CURDIR}

USE_GNOME=	gtk20
CONFIGURE_ARGS=--with-gtk

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 1000000
BROKEN=		does not link against GTK2 on FreeBSD 10+
.endif

pre-install:
	@${REINPLACE_CMD} -e 's|base [$$][(]GTKSRCDIR[)] data|$$(GTKSRCDIR)|g' \
		${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
