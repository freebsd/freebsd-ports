# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.33
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=PERL PYTHON UNIQUE
OPTIONS_SUB=	yes
UNIQUE_DESC=	Remote controle backend support

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

PERL_CONFIGURE_OFF=	--without-perl
PERL_USES=		perl5
PYTHON_CONFIGURE_OFF=	--without-python
RUBY_CONFIGURE_OFF=	--without-ruby
UNIQUE_CONFIGURE_OFF=	--without-unique
UNIQUE_LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
