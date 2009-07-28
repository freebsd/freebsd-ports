# New ports collection makefile for:	gwyddion
# Date created:				2006-08-06
# Whom:					Yeti <yeti@gwyddion.net>
#
# $FreeBSD$
#

PORTNAME=	gwyddion
PORTVERSION=	2.16
CATEGORIES=	science graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}

MAINTAINER=	yeti@gwyddion.net
COMMENT=	A gtk2 based SPM data visualization and analysis tool

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		fftw3.5:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-pascal --disable-pygwy --without-kde4-thumbnailer

MAKE_ARGS=	pkgconfigdatadir=${PREFIX}/libdata/pkgconfig

USE_GNOME=	desktopfileutils gnomemimedata gtk20 libxml2
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=		gwyddion.1 gwyddion-thumbnailer.1
MAN3=		Gwyddion::dump.3pm

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITHOUT_GCONF) || exists(${LOCALBASE}/bin/gconftool-2)
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	gwyddion-thumbnailer.schemas
.endif

# Fix shared library versioning and inhibit installation of .la files manually.
# Ports libtool + ltverhack fixes versions but it installs static versions of
# modules, so one would have to hack it too.
#
# Inhibit installation of excessive API documentation.  Option
# --disable-gtk-doc disables only building, not installation of documentation
# present in the source tarball.
post-patch:
	${REINPLACE_CMD} -e \
		'/freebsd-elf)/,/;;/ s|major="\.$$current"|major=.`expr $$current - $$age`|; \
		 /freebsd-elf)/,/;;/ s|versuffix="\.$$current"|versuffix="$$major"|; \
		 /# Install the pseudo-library/,/^$$/d' \
		${WRKSRC}/ltmain.sh
	@${REINPLACE_CMD} -e '/^SUBDIRS =/,/[^\]$$/d' ${WRKSRC}/devel-docs/Makefile.in

.include <bsd.port.mk>
