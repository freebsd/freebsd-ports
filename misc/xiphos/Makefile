# New ports collection makefile for: xiphos
# Date created:   February 2, 2009
# Whom:           Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xiphos
PORTVERSION=	3.1.4
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.1.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS} \
		docbook2html:${PORTSDIR}/textproc/docbook-utils \
		gnome-doc-tool:${PORTSDIR}/textproc/gnome-doc-utils \
		nspr>=4.8:${PORTSDIR}/devel/nspr

USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomelibs gtkhtml3 \
		intlhack libgsf

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure \
		--prefix=${PREFIX} --enable-gtkhtml --debug-level=optimized

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

.include <bsd.port.mk>
