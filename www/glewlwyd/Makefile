PORTNAME=	glewlwyd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Single Sign On server, multiple factor authentication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Doesn't build, ld: error: duplicate symbol
EXPIRATION_DATE=2022-03-31

USES=		cmake pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest
GH_TAGNAME=	e1ea98a

BUILD_DEPENDS+=	yder>0:devel/yder
BUILD_DEPENDS+=	orcania>0:devel/orcania
BUILD_DEPENDS+=	ulfius>0:www/ulfius
BUILD_DEPENDS+=	hoel>0:devel/hoel
BUILD_DEPENDS+=	oath-toolkit>0:security/oath-toolkit

LIB_DEPENDS+=	libjansson.so:devel/jansson
LIB_DEPENDS+=	libnettle.so:security/nettle
LIB_DEPENDS+=	libhoel.so:devel/hoel

LIB_DEPENDS+=	liboath.so:security/oath-toolkit
LIB_DEPENDS+=	libjwt.so:www/libjwt
LIB_DEPENDS+=	libgnutls.so:security/gnutls
LIB_DEPENDS+=	libconfig.so:devel/libconfig

LIB_DEPENDS+=	liblber.so:net/openldap24-client

RUN_DEPENDS+=	yder>0:devel/yder
RUN_DEPENDS+=	ulfius>0:www/ulfius
RUN_DEPENDS+=	libjwt>0:www/libjwt
RUN_DEPENDS+=	libcbor>0:devel/libcbor
RUN_DEPENDS+=	libmicrohttpd>0:www/libmicrohttpd
RUN_DEPENDS+=	gnutls>0:security/gnutls
RUN_DEPENDS+=	libconfig>0:devel/libconfig
RUN_DEPENDS+=	orcania>0:devel/orcania
RUN_DEPENDS+=	oath-toolkit>0:security/oath-toolkit

CMAKE_ARGS+=	-DWITH_JOURNALD=off
CMAKE_ARGS+=	-DWITH_USER_LDAP=off
CMAKE_ARGS+=	-DWITH_CLIENT_LDAP=off
CMAKE_ARGS+=	-DLIBOATH_INCLUDE_DIR=${PREFIX}/include/liboath
CMAKE_ARGS+=	-DLIBCBOR_INCLUDE_DIR=${PREFIX}/include/cbor
CMAKE_ARGS+=	-DLIBCBOR_LIBRARY=${PREFIX}/lib/libcbor.so
CMAKE_ARGS+=	-DWITH_SCHEME_WEBAUTHN=off

# -DWITH_PGSQL=off -DWITH_SCHEME_WEBAUTHN=off

SUB_FILES=	glewlwyd glewlwyd.conf.sample

USERS=		glewlwyd
GROUPS=		glewlwyd

USE_LDCONFIG+=	${PREFIX}/lib/glewlwyd/client
USE_LDCONFIG+=	${PREFIX}/lib/glewlwyd/plugin
USE_LDCONFIG+=	${PREFIX}/lib/glewlwyd/scheme
USE_LDCONFIG+=	${PREFIX}/lib/glewlwyd/user

do-install:
	# make all our dirs first
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
#	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glewlwyd/client
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glewlwyd/plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/glewlwyd/user
	${MKDIR} ${STAGEDIR}${WWWDIR}

	${INSTALL_SCRIPT}  ${WRKDIR}/glewlwyd        ${STAGEDIR}${PREFIX}/etc/rc.d/

	${INSTALL_PROGRAM} ${WRKDIR}/.build/glewlwyd ${STAGEDIR}${PREFIX}/sbin/

	# move these files so they don't get clobbered during upgrade
	${INSTALL_SCRIPT}  ${WRKDIR}/glewlwyd.conf.sample ${STAGEDIR}${ETCDIR}

	${MV} ${WRKSRC}/webapp/config.json.sample ${STAGEDIR}${ETCDIR}/config.json.sample

	# remove this file because we're installing a symlink here
	${RM} ${STAGEDIR}${DATADIR}/webapp/config.json

	# create a symlink
	${LN} -sf ${ETCDIR}/config.json ${STAGEDIR}${WWWDIR}/config.json

	${INSTALL_LIB} ${WRKDIR}/.build/libclientmoddatabase.so    ${STAGEDIR}${PREFIX}/lib/glewlwyd/client

	${INSTALL_LIB} ${WRKDIR}/.build/libprotocol_oauth2.so      ${STAGEDIR}${PREFIX}/lib/glewlwyd/plugin
	${INSTALL_LIB} ${WRKDIR}/.build/libprotocol_oidc.so        ${STAGEDIR}${PREFIX}/lib/glewlwyd/plugin
	${INSTALL_LIB} ${WRKDIR}/.build/libprotocol_register.so    ${STAGEDIR}${PREFIX}/lib/glewlwyd/plugin

	${INSTALL_LIB} ${WRKDIR}/.build/libschememodcertificate.so ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme
	${INSTALL_LIB} ${WRKDIR}/.build/libschememodemail.so       ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme
	${INSTALL_LIB} ${WRKDIR}/.build/libschememodhttp.so        ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme
	${INSTALL_LIB} ${WRKDIR}/.build/libschememodotp.so         ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme
	${INSTALL_LIB} ${WRKDIR}/.build/libschememodpassword.so    ${STAGEDIR}${PREFIX}/lib/glewlwyd/scheme

	${INSTALL_LIB} ${WRKDIR}/.build/libusermoddatabase.so      ${STAGEDIR}${PREFIX}/lib/glewlwyd/user
	${INSTALL_LIB} ${WRKDIR}/.build/libusermodhttp.so          ${STAGEDIR}${PREFIX}/lib/glewlwyd/user

	${INSTALL_MAN} ${WRKSRC}/CHANGELOG.md                      ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/README.md                         ${STAGEDIR}${DATADIR}

	(cd ${WRKSRC}/docs   && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

	(cd ${WRKSRC}/webapp && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
