# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	mc
PORTVERSION=	4.8.8
PORTREVISION=	0
CATEGORIES=	misc shells
MASTER_SITES=	http://ftp.osuosl.org/pub/midnightcommander/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LICENSE=	GPLv3

LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2

CONFLICTS=	mc-light-4*

USES=		pkgconfig
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_PERL5=	yes
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${UNZIP_CMD} UNZIP=${UNZIP_CMD}
USE_AUTOTOOLS=	libtool

PORTDATA=	*

OPTIONS_DEFINE=	SLANG ICONV NLS EDIT X11 SUBSHELL SMB
EDIT_DESC=	Build with internal editor
SUBSHELL_DESC=	Build with subshell support

OPTIONS_DEFAULT=	SLANG ICONV NLS EDIT X11 SUBSHELL SMB

post-patch:
	${REINPLACE_CMD} -e 's/SUBDIRS = intl/SUBDIRS =/' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/saved_CPPFLAGS="-ltermcap/saved_CPPFLAGS="/' ${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSMB} && !defined(MINIMAL)
CONFIGURE_ARGS+=--enable-vfs-smb --with-configdir=${LOCALBASE}/etc\
		--with-codepagedir=${LOCALBASE}/etc/codepages
.endif

.if ${PORT_OPTIONS:MICONV} && !defined(MINIMAL)
USES+=		iconv
.else
CONFIGURE_ARGS+=--disable-charset
.endif

.if ! ${PORT_OPTIONS:MNLS} && !defined(MINIMAL)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		gettext
PLIST_SUB+=	NLS=""
_MANLANG=	es hu it pl ru sr
.endif

.if ! ${PORT_OPTIONS:MX11} && !defined(MINIMAL)
CONFIGURE_ARGS+=--without-x
.else
USE_XORG=	x11 xext
.endif

.if ! ${PORT_OPTIONS:MEDIT} && !defined(MINIMAL)
CONFIGURE_ARGS+=--without-edit
PLIST_SUB+=	EDITOR="@comment "
.else
PLIST_SUB+=	EDITOR=""
.endif

.if ! ${PORT_OPTIONS:MSLANG} && !defined(MINIMAL)
CONFIGURE_ARGS+=--with-screen=ncurses
.else
LIB_DEPENDS+=	slang:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=--with-screen=slang --with-slang-includes=${LOCALBASE}/include
.endif

.if ! ${PORT_OPTIONS:MSUBSHELL} && !defined(MINIMAL)
CONFIGURE_ARGS+=--without-subshell
.endif

MAN1=		mc.1 mcedit.1 mcview.1
_MAN1=		mc.1
.for lang in ${_MANLANG}
_MANPAGES+=	${_MAN1:S%^%${MAN1PREFIX}/man/${lang}/man1/%}
.endfor

.include <bsd.port.mk>
