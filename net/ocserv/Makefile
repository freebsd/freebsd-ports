PORTNAME=	ocserv
DISTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	net net-vpn security
MASTER_SITES=	https://www.infradead.org/ocserv/download/

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Server implementing the AnyConnect SSL VPN protocol
WWW=		https://ocserv.gitlab.io/www/index.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed \
		ipcalc:net-mgmt/ipcalc
LIB_DEPENDS=	libev.so:devel/libev \
		libgnutls.so:security/gnutls \
		libiconv.so:converters/libiconv \
		liblz4.so:archivers/liblz4 \
		libnettle.so:security/nettle \
		liboath.so:security/oath-toolkit \
		libpcl.so:devel/pcl \
		libprotobuf-c.so:devel/protobuf-c \
		libtalloc.so:devel/talloc \
		libtasn1.so:security/libtasn1

USES=		autoreconf cpe gettext-tools gperf libtool localbase ncurses \
		pathfix pkgconfig readline tar:xz

CPE_VENDOR=	infradead
USE_RC_SUBR=	ocserv
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-namespaces \
		--without-geoip \
		--without-http-parser

USERS=		_ocserv
GROUPS=		_ocserv

PLIST_SUB=	GROUPS="${GROUPS}" \
		USERS="${USERS}"
PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTEXAMPLES=	profile.xml sample.config sample.passwd

OPTIONS_DEFINE=	DOCS EXAMPLES GSSAPI MAXMIND RADIUS

MAXMIND_DESC=	Use Maxmind GeoIP library

GSSAPI_LIB_DEPENDS=	libkrb5support.so:security/krb5
GSSAPI_USES=		gssapi:mit
GSSAPI_CONFIGURE_OFF=	--without-gssapi
MAXMIND_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
MAXMIND_CONFIGURE_OFF=	--without-maxmind
RADIUS_LIB_DEPENDS=	libradcli.so:net/radcli
RADIUS_CONFIGURE_OFF=	--without-radius

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's|/usr/bin/ocserv\\-fw|${PREFIX}/libexec/ocserv\\-fw|g' \
		${WRKSRC}/doc/ocserv.8
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%ETCDIR%%|${ETCDIR}|g' \
		-e 's|%%USERS%%|${USERS}|g' \
		-e 's|%%GROUPS%%|${GROUPS}|g' \
		${WRKSRC}/doc/sample.config \
		${WRKSRC}/src/main-user.c
.if "${PREFIX}" != "" && "${PREFIX}" != "/" && "${PREFIX}" != "/usr"
	${REINPLACE_CMD} -E 's|^(#define DEFAULT_CFG_FILE ")(/etc/ocserv/ocserv.conf")|\1${PREFIX}\2|' ${WRKSRC}/src/config.c
	${REINPLACE_CMD} -E 's|^(#define DEFAULT_OCPASSWD ")(/etc/ocserv/ocpasswd")|\1${PREFIX}\2|' ${WRKSRC}/src/ocpasswd/ocpasswd.c
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ocserv ${STAGEDIR}/var/run/ocserv
	${INSTALL_DATA} ${WRKSRC}/doc/sample.config ${STAGEDIR}${PREFIX}/etc/ocserv/ocserv.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
