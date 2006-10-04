# New ports collection makefile for:	gwyddion
# Date created:				2006-08-06
# Whom:					Yeti <yeti@gwyddion.net>
#
# $FreeBSD$
#

PORTNAME=	gwyddion
PORTVERSION=	2.0
CATEGORIES=	science graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yeti@gwyddion.net
COMMENT=	A gtk2 based SPM data visualization and analysis tool

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		fftw3.4:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-pascal

MAKE_ARGS=	pkgconfigdatadir=${PREFIX}/libdata/pkgconfig

USE_X_PREFIX=	yes
USE_GNOME=	desktopfileutils gnomemimedata gtk20 libxml2
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_LDCONFIG=	yes

MAN1=		gwyddion.1
MAN3=		Gwyddion::dump.3pm

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

# Inhibit installation of .la files.  Theoretically USE_AUTOTOOLS=libtool:15
# prevents that but in practice it doesn't work well and in addition the Ports
# libtool causes installation of static version of modules that are more work
# to get rid of than this.
#
# Inhibit installation of excessive API documentation.  Option
# --disable-gtk-doc disables only building, not installation of documentation
# present in the source tarball.
post-patch:
	@${REINPLACE_CMD} -e '/# Install the pseudo-library/,/^$$/d' ${WRKSRC}/ltmain.sh
	@${REINPLACE_CMD} -e '/^SUBDIRS =/,/[^\]$$/d' ${WRKSRC}/devel-docs/Makefile.in

# Remove private header installed by mistake
post-install:
	${RM} ${PREFIX}/include/gwyddion/libgwydgets/gwydgetmarshals.h

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${LOCALBASE}/bin/pod2man:${PORTSDIR}/textproc/p5-podlators
CONFIGURE_ENV+=	POD2MAN="${LOCALBASE}/bin/pod2man"
.endif

.include <bsd.port.post.mk>
