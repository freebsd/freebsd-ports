# Created by: James Earl
# $FreeBSD$

PORTNAME=	xmlroff
PORTVERSION=	0.6.2
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter that produces PDF and PostScript

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libfo>=0.6.2:textproc/libfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf gmake gettext libtool pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libgnomeprint libartlgpl2 pango glib20 \
		libxslt libxml2 gdkpixbuf2
GH_ACCOUNT=	xmlroff
GH_PROJECT=	xmlroff
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-html-dir=${PREFIX}/share/doc
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ENABLE=	gtk-doc
DOCS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-doc.pc:textproc/gtk-doc

.include <bsd.port.mk>
