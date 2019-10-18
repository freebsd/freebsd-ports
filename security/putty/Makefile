# $FreeBSD$

PORTNAME=	putty
PORTVERSION=	0.73
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/${PORTVERSION}/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure shell and telnet client
# test plan: test ALL 4 GSSAPI_* options, ALL 3 GTK options, WITH_DEBUG=yes build.

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE

USES=		cpe gmake pkgconfig

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
MAKEFILE=	Makefile.gtk

CPE_VENDOR=	simon_tatham

PLIST_FILES=	bin/plink bin/pscp bin/psftp bin/puttygen
PLIST_FILES+=	man/man1/plink.1.gz man/man1/pscp.1.gz man/man1/psftp.1.gz man/man1/puttygen.1.gz

OPTIONS_RADIO=		TOOLKIT
OPTIONS_RADIO_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=GSSAPI_BASE GTK3
OPTIONS_SINGLE=	GSSAPI_SELECT
OPTIONS_SINGLE_GSSAPI_SELECT=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

CONFLICTS_INSTALL?=	pssh-[0-9]* putty-gtk2-[0-9]* putty-nogtk-[0-9]*

.include <bsd.port.options.mk>

CFLAGS+=	-DBSD_PTYS -DOMIT_UTMP -DIPV6 -DHAVE_FUTIMES
LDFLAGS+=	-Wl,--as-needed

.if (${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}) && !defined(WITHOUT_X11)
USES+=		xorg
USE_XORG=	x11
.if ${PORT_OPTIONS:MGTK2}
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKE_ARGS+=	PUTTY_WITH_GTK=yes GTK_CONFIG="pkg-config gtk+-2.0 x11 --cflags"
.endif
.if ${PORT_OPTIONS:MGTK3}
USES+=		gnome
USE_GNOME=	cairo gdkpixbuf2 gtk30
MAKE_ARGS+=	PUTTY_WITH_GTK=yes GTK_CONFIG="pkg-config gtk+-3.0 x11 --cflags"
.endif

PLIST_FILES+=	bin/pageant bin/pterm bin/putty bin/puttytel
PLIST_FILES+=	man/man1/pageant.1.gz man/man1/pterm.1.gz man/man1/putty.1.gz man/man1/puttytel.1.gz
PLIST_FILES+=	share/pixmaps/putty.ico
DESKTOP_ENTRIES="PuTTY" \
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
_COMPAT=		-DNO_GSSAPI
.endif

_COMPAT+=	-DOMIT_UTMP

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
XFLAGS=		-DDEBUG
_COMPAT+=	-DDEBUG
.endif

# upstream sets -Werror - there are no issues on 9.1-FreeBSD amd64
# currently, but override it nonetheless.
XFLAGS+=	-Wno-error

MAKE_ARGS+=	COMPAT="${_COMPAT}" \
		CC="${CC}" \
		XFLAGS="${XFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-patch:
	@${REINPLACE_CMD} -e 's,prefix=/usr/local,prefix=${PREFIX},;\
			      s,make,${MAKE_CMD},'\
		${WRKSRC}/${MAKEFILE}

post-install:
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../windows/putty.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.mk>
