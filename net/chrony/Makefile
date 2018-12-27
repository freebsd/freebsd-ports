# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	chrony
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	yonas@fizk.net
COMMENT=	System clock synchronization client and server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USERS=		chronyd
GROUPS=		chronyd

USES=		cpe gmake libedit
CPE_VENDOR=	tuxfamily
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--chronyvardir=/var/db/${PORTNAME} \
		--sysconfdir=${PREFIX}/etc --mandir=${MANPREFIX}/man \
		--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		--with-readline-library=${LOCALBASE}/lib \
		--with-user=chronyd --without-tomcrypt
USE_RC_SUBR=	chronyd

ALL_TARGET=	all
INSTALL_TARGET=	install
PORTDOCS=	FAQ NEWS README
PORTEXAMPLES=	chrony.conf.example1 chrony.conf.example2 \
		chrony.conf.example3 chrony.keys.example

# XXX: there are also other potentially useful options worth looking into:
#  --disable-pps        Disable PPS API support
OPTIONS_DEFINE=		DOCS EXAMPLES IPV6 NETTLE NSS
OPTIONS_DEFAULT=	NETTLE

NETTLE_DESC=		Nettle crypto library support
NSS_DESC=		Add support for more hashing algorithms

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-ipv6
NETTLE_CONFIGURE_OFF=	--without-nettle
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NSS_BROKEN=		Crashes on startup with NSS. See https://bugs.freebsd.org/223840
NSS_CONFIGURE_OFF=	--without-nss
NSS_LIB_DEPENDS=	libfreebl3.so:security/nss
NSS_USES=		pkgconfig

post-patch:
	@cd ${WRKSRC}/examples && \
		${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' ${PORTEXAMPLES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chronyc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/chronyd
	${INSTALL_DATA} ${WRKSRC}/examples/chrony.conf.example3 \
		${STAGEDIR}${PREFIX}/etc/chrony.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
