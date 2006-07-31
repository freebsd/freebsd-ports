# New ports collection makefile for:   uim-m17nlib
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-m17nlib-nox11
.else
PKGNAMESUFFIX=	-m17nlib
.endif

COMMENT=	Uim plugin using m17n library input method

LIB_DEPENDS=	m17n.1:${PORTSDIR}/devel/m17n-lib \
		uim.2:${PORTSDIR}/textproc/uim

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-m17nlib

UIM_SLAVE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-uim_Makefile.in

do-build:
	(cd ${WRKSRC}/uim && ${GMAKE} LIBS="-luim" libuim-m17nlib.la)

do-install:
	(cd ${WRKSRC}/uim && \
	${GMAKE} uim_plugin_LTLIBRARIES=libuim-m17nlib.la install-uim_pluginLTLIBRARIES)

post-install:
.if defined(WITHOUT_X11)
	${LOCALBASE}/bin/uim-module-manager --register m17nlib
.else
	${X11BASE}/bin/uim-module-manager --register m17nlib
.endif

.include "${MASTERDIR}/Makefile"
