# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.38
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_GNOME=	gconf2 gtk20 libxml2
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk-doc \
		--without-kde4-thumbnailer
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gwyddion-thumbnailer.schemas

OPTIONS_DEFINE=		PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=	PERL PYTHON UNIQUE
OPTIONS_SUB=		yes

PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl
PYTHON_USES=		python
PYTHON_USE=		gnome=pygtksourceview
PYTHON_CONFIGURE_ENABLE=	pygwy
PYTHON_CONFIGURE_WITH=	gtksourceview python
RUBY_USE=		ruby=yes
RUBY_CONFIGURE_WITH=	ruby
UNIQUE_DESC=		Remote control backend support
UNIQUE_LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
UNIQUE_CONFIGURE_WITH=	unique

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
