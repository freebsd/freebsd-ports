PORTNAME=	glewlwyd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.2
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Single Sign On server, multiple factor authentication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yder>1.4.14:devel/yder \
		orcania>2.2.1:devel/orcania \
		ulfius>2.7.7:www/ulfius \
		hoel>1.4.18:devel/hoel \
		oath-toolkit>0:security/oath-toolkit

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libnettle.so:security/nettle \
		libhoel.so:devel/hoel \
		liboath.so:security/oath-toolkit \
		libjwt.so:www/libjwt \
		libgnutls.so:security/gnutls \
		libconfig.so:devel/libconfig \
		liblber.so:net/openldap24-client \
		librhonabwy.so:security/rhonabwy \
		libiddawc.so:security/iddawc

RUN_DEPENDS=	yder>1.4.14:devel/yder \
		ulfius>2.7.7:www/ulfius \
		libjwt>0:www/libjwt \
		libcbor>0:devel/libcbor \
		libmicrohttpd>0:www/libmicrohttpd \
		gnutls>0:security/gnutls \
		libconfig>0:devel/libconfig \
		orcania>2.2.1:devel/orcania \
		oath-toolkit>0:security/oath-toolkit

USES=		cmake cpe pgsql sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

CPE_VENDOR=	glewlwyd_project

CMAKE_ARGS=	-DWITH_JOURNALD=off \
		-DWITH_USER_LDAP=off \
		-DWITH_CLIENT_LDAP=off \
		-DLIBOATH_INCLUDE_DIR=${PREFIX}/include/liboath \
		-DLIBCBOR_INCLUDE_DIR=${PREFIX}/include/cbor \
		-DLIBCBOR_LIBRARY=${PREFIX}/lib/libcbor.so \
		-DWITH_SCHEME_WEBAUTHN=off \
		-DDOWNLOAD_DEPENDENCIES=off

SUB_FILES=	glewlwyd glewlwyd.conf.sample

USERS=		glewlwyd
GROUPS=		glewlwyd

post-install:
	# make all our dirs first
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
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

	${INSTALL_MAN} ${WRKSRC}/CHANGELOG.md                      ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/README.md                         ${STAGEDIR}${DATADIR}

	(cd ${WRKSRC}/docs   && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

	(cd ${WRKSRC}/webapp && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
