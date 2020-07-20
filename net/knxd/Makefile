# Created by: mfechner@FreeBSD.org
# $FreeBSD$

PORTNAME=	knxd
PORTVERSION=	0.14.39
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Advanced router/gateway for KNX

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libev.so:devel/libev \
		libfmt.so:devel/libfmt

USES=		autoreconf compiler:c11 gmake libtool pkgconfig
USE_RC_SUBR=	knxd
USE_GITHUB=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
GH_ACCOUNT=	knxd
GH_PROJECT=	knxd
GH_TAGNAME=	746a8d85dfdc4c456a9b832eca358a062a2b351d
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-systemd --disable-usb \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-I${LOCALBASE}/include -L/${LOCALBASE}/lib"

post-patch:
	# Replace script for version detection with PORTREVISION as the repository does not have a .git repo and therefor the script fails
	@${REINPLACE_CMD} \
		-e "s|^\(AC_INIT.*\)m4.*|\1\[${PORTVERSION}\])|" \
			${WRKSRC}/configure.ac

post-install:
	(cd ${WRKSRC} && src/server/knxd_args -d -e 15.15.1 -E 15.15.2:8 -D -T -S -B single -b ipt:192.168.0.117 -u /var/run/knxd > ${STAGEDIR}${PREFIX}/etc/knxd.conf.sample)

.include <bsd.port.mk>
