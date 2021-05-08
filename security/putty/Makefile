PORTNAME=	putty
PORTVERSION=	0.75
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/${PORTVERSION}/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure shell and telnet client
# test plan: test ALL 4 GSSAPI_* options, ALL 3 GTK options, WITH_DEBUG=yes build.

LICENSE=	MIT
LICENSE_FILE=	${PATCH_WRKSRC}/LICENCE

USES=		cpe gmake pkgconfig
CPE_VENDOR=	simon_tatham

MAKEFILE=	Makefile.gtk
MAKE_ARGS+=	"prefix=${PREFIX}"

CONFLICTS_INSTALL?=	pssh-[0-9]* putty-gtk2-[0-9]* putty-nogtk-[0-9]*

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/unix

PLIST_FILES=	bin/plink \
		bin/pscp \
		bin/psftp \
		bin/puttygen \
		man/man1/plink.1.gz \
		man/man1/pscp.1.gz \
		man/man1/psftp.1.gz \
		man/man1/puttygen.1.gz

OPTIONS_DEFAULT=		GSSAPI_BASE GTK3
OPTIONS_RADIO=			TOOLKIT
OPTIONS_RADIO_TOOLKIT=		GTK2 GTK3
OPTIONS_SINGLE=			GSSAPI_SELECT
OPTIONS_SINGLE_GSSAPI_SELECT=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT \
				GSSAPI_NONE

.include <bsd.port.options.mk>

CFLAGS+=	-DBSD_PTYS -DHAVE_FUTIMES -DIPV6 -DOMIT_UTMP
LDFLAGS+=	-lm -Wl,--as-needed

.if (${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}) && !defined(WITHOUT_X11)
USES+=		xorg
USE_XORG=	x11
. if ${PORT_OPTIONS:MGTK3}
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk30
MAKE_ARGS+=	GTK_CONFIG="pkg-config gtk+-3.0 x11 --cflags" \
		PUTTY_WITH_GTK=yes
. elif ${PORT_OPTIONS:MGTK2}
 USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKE_ARGS+=	GTK_CONFIG="pkg-config gtk+-2.0 x11 --cflags" \
		PUTTY_WITH_GTK=yes
. endif

PLIST_FILES+=	bin/pageant \
		bin/pterm \
		bin/putty \
		bin/puttytel \
		man/man1/pageant.1.gz \
		man/man1/pterm.1.gz \
		man/man1/putty.1.gz \
		man/man1/puttytel.1.gz \
		share/pixmaps/putty.ico
DESKTOP_ENTRIES=	"PuTTY" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
			"${PORTNAME}" \
			"" \
			false
.else
MAKE_ARGS+=	GTK_CONFIG=:
.endif

.if ${PORT_OPTIONS:MGSSAPI_BASE}
USES+=		gssapi:base,flags
MAKE_ARGS+=	KRB5CONFIG=${KRB5CONFIG}
.elif ${PORT_OPTIONS:MGSSAPI_HEIMDAL}
USES+=		gssapi:heimdal,flags
MAKE_ARGS+=	KRB5CONFIG=${KRB5CONFIG}
.elif ${PORT_OPTIONS:MGSSAPI_MIT}
USES+=		gssapi:mit,flags
MAKE_ARGS+=	KRB5CONFIG=${KRB5CONFIG}
.else
_COMPAT=	-DNO_GSSAPI
.endif

_COMPAT+=	-DOMIT_UTMP

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
XFLAGS=		-DDEBUG
_COMPAT+=	-DDEBUG
.endif

MAKE_ARGS+=	CC="${CC}" \
		COMPAT="${_COMPAT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		XFLAGS="${XFLAGS}"

post-install:
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../windows/putty.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.mk>
