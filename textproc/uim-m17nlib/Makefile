# New ports collection makefile for:   uim-m17nlib
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-m17nlib

COMMENT=	Uim plugin using m17n library input method

RUN_DEPENDS=	uim-module-manager:${PORTSDIR}/textproc/uim
LIB_DEPENDS=	m17n.1:${PORTSDIR}/devel/m17n-lib

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-m17nlib

UIM_SLAVE=	yes

IGNORE=		requires m17n-lib-1.3.1 or later

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} libuim-m17nlib.la)

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-m17nlib.la install-uim_pluginLTLIBRARIES)

post-install:
	${X11BASE}/bin/uim-module-manager --register m17nlib

.include "${MASTERDIR}/Makefile"
