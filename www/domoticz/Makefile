# $FreeBSD$

PORTNAME=	domoticz
PORTVERSION=	2.${DOMOTICZ_REL}
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	kiwi@oav.net
COMMENT=	Home Automation System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libboost_system.so:devel/boost-libs \
		libboost_python.so:devel/boost-python-libs \
		libtelldus-core.so:comms/telldus-core

# This hack is to get rid of dependency of git while building
# the package.
DOMOTICZ_REL=	4268
DOMOTICZ_TS=	1453185544
USE_GITHUB=	yes
GH_TAGNAME=	12f5a19

USES=		cmake execinfo iconv lua:52 pkgconfig sqlite

USE_RC_SUBR=	domoticz

USERS=		domoticz
GROUPS=		domoticz

CMAKE_ARGS= 	-DUSE_BUILTIN_SQLITE="NO" \
		-DUSE_BUILTIN_LUA="NO" \
		-DUSE_STATIC_BOOST="NO" \
		-DUSE_BUILTIN_ZLIB="NO" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}/domoticz

post-patch:
	@${REINPLACE_CMD} -e "s,XXXDOMOTICZXXX,${DOMOTICZ_REL},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,\/opt,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,XXXPREFIXXX,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,XXXDOMOTICZXXX,${DOMOTICZ_REL},g" ${WRKSRC}/getgit.cmake
	@${REINPLACE_CMD} -e "s,XXXHASHXXX,${GH_TAGNAME},g" ${WRKSRC}/getgit.cmake
	@${REINPLACE_CMD} -e "s,XXXTIMEXXX,${DOMOTICZ_TS},g" ${WRKSRC}/getgit.cmake
	@${REINPLACE_CMD} -e "/^ADD_PRECOMPILED_HEADER/ d" ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
