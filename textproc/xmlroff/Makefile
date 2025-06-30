PORTNAME=	xmlroff
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter that produces PDF and PostScript
WWW=		http://xmlroff.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libfo>=0.6.2:textproc/libfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf gmake gnome gettext localbase libtool pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libartlgpl2 pango glib20 \
		libxslt libxml2 gdkpixbuf
GH_ACCOUNT=	xmlroff
GH_PROJECT=	xmlroff
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc --enable-man \
		--disable-gp
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ENABLE=	gtk-doc
DOCS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-doc.pc:textproc/gtk-doc

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/docs/Makefile.am

.include <bsd.port.mk>
