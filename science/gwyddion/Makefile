# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.31
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		fftw3:${PORTSDIR}/math/fftw3 \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=PERL PYTHON UNIQUE
UNIQUE_DESC=	Remote controle backend support

USE_XZ=		yes
USES=		desktop-file-utils gettext pathfix shared-mime-info
USE_GNOME=	gconf2 gtk20 libxml2
USE_GL=		glu
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk-doc \
		--disable-pygwy --without-gtksourceview \
		--without-kde4-thumbnailer
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gwyddion-thumbnailer.schemas

MAN1=		gwyddion.1 gwyddion-thumbnailer.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
MAN3+=		Gwyddion::dump.3pm
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
CONFIGURE_ARGS+=--without-ruby
PLIST_SUB+=	RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1.0:${PORTSDIR}/x11-toolkits/unique
.else
CONFIGURE_ARGS+=--without-unique
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
