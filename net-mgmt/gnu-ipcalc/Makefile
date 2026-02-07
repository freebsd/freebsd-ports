PORTNAME=	ipcalc
DISTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	gnu-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Modern network address calculation tool for IPv4 and IPv6
WWW=		https://gitlab.com/ipcalc/ipcalc/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase meson pkgconfig
USE_GITLAB=	yes
MESON_ARGS=	-Duse_geoip=disabled

CONFLICTS_INSTALL=	ipcalc

OPTIONS_DEFINE=		MANPAGES MAXMINDDB
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes
MAXMINDDB_DESC=		Enable GeoIP1 + GeoIP2 Support

MANPAGES_BUILD_DEPENDS=		ronn:textproc/rubygem-ronn
MAXMINDDB_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
MAXMINDDB_MESON_ENABLED=	use_maxminddb
MAXMINDDB_SUB_FILES=		pkg-message

post-patch-MAXMINDDB-on:
	@${REINPLACE_CMD} -e "s|/usr/share|${LOCALBASE}/share|g" \
		${WRKSRC}/ipcalc-maxmind.c

.include <bsd.port.mk>
