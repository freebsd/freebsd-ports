PORTNAME=	knxd
PORTVERSION=	0.14.72
CATEGORIES=	net

# make is compatible with fmt >= 10, https://github.com/knxd/knxd/pull/549
#PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
#PATCHFILES=	797283251470786bffd6586571407337da899d30.patch:-p1

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Advanced router/gateway for KNX
WWW=		https://github.com/knxd/knxd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libev.so:devel/libev \
		libfmt.so:devel/libfmt

USES=		autoreconf compiler:c11 gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-systemd --disable-usb \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-I${LOCALBASE}/include -L/${LOCALBASE}/lib"
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	knxd

INSTALL_TARGET=	install-strip

post-patch:
	# Replace script for version detection with PORTREVISION as the repository does not have a .git repo and therefor the script fails
	@${REINPLACE_CMD} \
		-e "s|^\(AC_INIT.*\)m4.*|\1\[${PORTVERSION}\])|" \
			${WRKSRC}/configure.ac

post-install:
	(cd ${WRKSRC} && src/server/knxd_args -d -e 15.15.1 -E 15.15.2:8 -D -T -S -B single -b ipt:192.168.0.117 -u /var/run/knxd > ${STAGEDIR}${PREFIX}/etc/knxd.conf.sample)

.include <bsd.port.mk>
