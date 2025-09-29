PORTNAME=	ntopng
PORTVERSION=	6.4.d20250813
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces
WWW=		https://www.ntop.org/products/traffic-analysis/ntop/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librrd.so:databases/rrdtool \
		libzmq.so:net/libzmq4 \
		libcurl.so:ftp/curl \
		libndpi.so:net/ndpi \
		libjson-c.so:devel/json-c \
		libsodium.so:security/libsodium \
		libmaxminddb.so:net/libmaxminddb \
		libexpat.so:textproc/expat2 \
		libzstd.so:archivers/zstd \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libhiredis.so:databases/hiredis
BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c++11-lang cpe gmake libtool localbase \
		lua:54 mysql pathfix pkgconfig shebangfix sqlite ssl

SUB_FILES=	ntopng-geoip2update.sh pkg-deinstall pkg-message
SHEBANG_FILES=	httpdocs/misc/ntopng-add-user.sh \
		httpdocs/misc/ntopng-utils-manage-config.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ndpi-includes=${LOCALBASE}/include/ndpi

USERS=		ntopng
GROUPS=		ntopng
PLIST_SUB=	NTOPNGUSER="${USERS}" NTOPNGROUP="${GROUPS}"

USE_GITHUB=	yes
GH_TUPLE=	ntop:ntopng-dist:de6d656:dist/httpdocs/dist
GH_ACCOUNT=	ntop
GH_TAGNAME=	7ebfa69

CPE_VENDOR=	ntop

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes

NLS_USES=	gettext

USE_RC_SUBR=	ntopng

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
