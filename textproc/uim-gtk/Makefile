# New ports collection makefile for:   uim-gtk
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gtk

COMMENT=	GTK+ modules of uim input method

USE_GNOME=	gtk20
RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-gtk2

UIM_SLAVE=	yes

do-install:
	(cd ${WRKSRC}/gtk && ${GMAKE} install)
	(cd ${WRKSRC}/helper && ${GMAKE} install)

.include "${MASTERDIR}/Makefile"
