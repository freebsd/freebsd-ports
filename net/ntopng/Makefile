PORTNAME=	ntopng
PORTVERSION=	6.6.d20260829
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces
WWW=		https://www.ntop.org/products/traffic-analysis/ntop/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/clickhouse/version.h:databases/clickhouse-cpp \
		bash:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libhiredis.so:databases/hiredis \
		libjson-c.so:devel/json-c \
		libmaxminddb.so:net/libmaxminddb \
		libndpi.so:net/ndpi \
		librrd.so:databases/rrdtool \
		libsodium.so:security/libsodium \
		libzmq.so:net/libzmq4 \
		libzstd.so:archivers/zstd

USES=		autoreconf compiler:c++11-lang cpe gmake libtool localbase \
		lua:54 pathfix pkgconfig shebangfix sqlite ssl
CPE_VENDOR=	ntop
USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_TAGNAME=	ad4d754
GH_TUPLE=	ntop:ntopng-dist:4a1dc74:dist/httpdocs/dist
USE_RC_SUBR=	ntopng

SHEBANG_FILES=	httpdocs/misc/ntopng-add-user.sh \
		httpdocs/misc/ntopng-utils-manage-config.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dynamic-ndpi \
		--with-ndpi-includes=${LOCALBASE}/include/ndpi

SUB_FILES=	ntopng-geoip2update.sh pkg-deinstall pkg-message

USERS=		ntopng
GROUPS=		ntopng
PLIST_SUB=	NTOPNGROUP="${GROUPS}" \
		NTOPNGUSER="${USERS}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%SSL_INC%%|${OPENSSLINC}|g' \
		-e 's|%%SSL_LIB%%|${OPENSSLLIB}|g' \
			${WRKSRC}/Makefile.in \
			${WRKSRC}/configure.ac.in
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ntopng
	${MKDIR} ${STAGEDIR}/var/db/ntopng
	${INSTALL_SCRIPT} ${WRKDIR}/ntopng-geoip2update.sh ${STAGEDIR}${PREFIX}/bin
	${RM} ${STAGEDIR}${DATADIR}/httpdocs/misc/ntopng-utils-manage-updates \
		${STAGEDIR}${DATADIR}/httpdocs/misc/ntopng-utils-manage-updates.in

.include <bsd.port.mk>
