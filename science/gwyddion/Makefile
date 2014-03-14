# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.35
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_GNOME=	gconf2 gtk20 libxml2
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk-doc \
		--disable-pygwy --without-gtksourceview \
		--without-kde4-thumbnailer
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gwyddion-thumbnailer.schemas

OPTIONS_DEFINE=		PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=	PERL PYTHON UNIQUE
OPTIONS_SUB=		yes

PERL_CONFIGURE_WITH=	perl
PERL_USES=		perl5
PYTHON_CONFIGURE_WITH=	python
PYTHON_USE=		PYTHON=yes
RUBY_CONFIGURE_WITH=	ruby
RUBY_USE=		RUBY=yes
UNIQUE_DESC=		Remote controle backend support
UNIQUE_CONFIGURE_WITH=	unique
UNIQUE_LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
