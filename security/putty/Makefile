PORTNAME=	putty
PORTVERSION=	0.77
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/${PORTVERSION}/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure shell and telnet client including xterm emulator
# test plan: test ALL 4 GSSAPI_* options, GTK3 yes/no, WITH_DEBUG=yes build.

LICENSE=	MIT
LICENSE_FILE=	${PATCH_WRKSRC}/LICENCE

USES=		cmake cpe perl5 pkgconfig
USE_PERL5=	build

CONFLICTS_INSTALL?=	pssh putty-nogtk

PLIST_FILES=	bin/plink \
		bin/pscp \
		bin/psftp \
		bin/psusan \
		bin/puttygen \
		share/man/man1/plink.1.gz \
		share/man/man1/pscp.1.gz \
		share/man/man1/psftp.1.gz \
		share/man/man1/psusan.1.gz \
		share/man/man1/puttygen.1.gz

OPTIONS_DEFINE=			GTK3
OPTIONS_DEFAULT=		GSSAPI_NONE GTK3
OPTIONS_SINGLE=			GSSAPI_SELECT
OPTIONS_SINGLE_GSSAPI_SELECT=	GSSAPI_MIT \
				GSSAPI_DYNAMIC \
				GSSAPI_NONE
GSSAPI_DYNAMIC_DESC=	EXPERIMENTAL dynamic runtime load of GSS libs

.include <bsd.port.options.mk>

LDFLAGS+=	-Wl,--as-needed

# XXX FIXME this is simplified on these assumptions:
# - we only support GTK3 in FreeBSD
#   (Putty would support EOL GTK2 and GTK1 as well)
# - Putty 0.77 cannot have X11 without the gdk/gdkx.h header i. e. GTK.
.if ${PORT_OPTIONS:MGTK3} && !defined(WITHOUT_X11)
USES+=		xorg
USE_XORG=	x11
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk30
CMAKE_ARGS+=	-DPUTTY_GTK_VERSION:STRING=3

PLIST_FILES+=	bin/pageant \
		bin/pterm \
		bin/putty \
		share/man/man1/pageant.1.gz \
		share/man/man1/pterm.1.gz \
		share/man/man1/putty.1.gz \
		share/pixmaps/putty.ico
DESKTOP_ENTRIES=	"PuTTY" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
			"${PORTNAME}" \
			"" \
			false
.else
# XXX FIXME HACK ALERT
# PUTTY_GTK_VERSION=OFF is not a valid choice, but manages to
# skip all version comparisons for GTK in cmake/gtk.cmake:
CMAKE_ARGS+=	-DPUTTY_GTK_VERSION:STRING=OFF
# this is standard stuff:
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_X11:BOOL=TRUE 
.endif

.if ${PORT_OPTIONS:MGSSAPI_HEIMDAL}
# does not compile currently
BROKEN=		GSSAPI_HEIMDAL does not compile as of putty 0.77
USES+=		gssapi:heimdal,flags
CMAKE_ARGS+=	-DPUTTY_GSSAPI:STRING=STATIC
.elif ${PORT_OPTIONS:MGSSAPI_MIT}
USES+=		gssapi:mit,flags
CMAKE_ARGS+=	-DPUTTY_GSSAPI:STRING=STATIC
.elif ${PORT_OPTIONS:MGSSAPI_DYNAMIC}
CMAKE_ARGS+=	-DPUTTY_GSSAPI:STRING=DYNAMIC
.else
# XXX FIXME buglet in putty 0.77: PUTTY_GSSAPI=OFF 
# does not appear to get NO_GSSAPI into .build/CMakeFiles/cmake.h,
# so we shove it down explicitly:
CMAKE_ARGS+=	-DPUTTY_GSSAPI:STRING=OFF -DNO_GSSAPI=ON
.endif

post-patch:
	# we don't want to inherit FreeBSD commits
	# as PUTTY Git commit revisions,
	# so pretend we do not have Git:
	${REINPLACE_CMD} '/FindGit/d' \
		${WRKSRC}/cmake/setup.cmake \
		${WRKSRC}/doc/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MGTK3}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/windows/putty.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.mk>
