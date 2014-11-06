# Created by: Dikshie <dikshie@sfc.wide.ad.jp>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.6.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	YAF is Yet Another Flowmeter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfixbuf.so:${PORTSDIR}/net/libfixbuf \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libpcre.so:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix perl5 pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc --enable-applabel --enable-plugins

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.if defined(WITH_DAG)
CONFIGURE_ARGS+=	--with-dag=${LOCALBASE}
.endif

post-install:
.for f in dhcp_fingerprints.conf yafApplabelRules.conf yafDPIRules.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/$f ${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor

.include <bsd.port.mk>
