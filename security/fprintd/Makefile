PORTNAME=	fprintd
DISTVERSIONPREFIX=	V_
DISTVERSION=	0_8_1
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon that provides fingerprint scanning functionality over D-Bus

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Very outdated, unsupported upstream which now have systemd as a non optional requirement
EXPIRATION_DATE=2022-12-31 

LIB_DEPENDS=	libfprint.so:security/libfprint \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libpolkit-gobject-1.so:sysutils/polkit

USES=		autoreconf:build gettext gmake gnome libtool pkgconfig
USE_GNOME=	intltool glib20

USE_GITHUB=	yes
GH_ACCOUNT=	freedesktop
GH_PROJECT=	libfprint-${PORTNAME}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	sysconfdir="${ETCDIR}/"

OPTIONS_DEFINE=	NLS PAM
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
PAM_CONFIGURE_ENABLE=	pam

# Remove doc build ;  Doesn't install with/without
# Also less deps needed
pre-configure:
	${REINPLACE_CMD} -e '/pushd/d ; /docize/d ; /popd/d' ${WRKSRC}/autogen.sh
	${REINPLACE_CMD} -e '73,81d' ${WRKSRC}/doc/Makefile.am
	${REINPLACE_CMD} -e '/DOC_CHECK/d' ${WRKSRC}/configure.ac
	(cd ${WRKSRC} && ${SETENV} NOCONFIGURE=1 ${SH} autogen.sh)

.include <bsd.port.mk>
