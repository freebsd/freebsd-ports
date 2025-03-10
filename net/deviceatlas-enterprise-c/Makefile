PORTNAME=	deviceatlas-enterprise-c
DISTVERSION=	3.2.3
CATEGORIES=	net devel
MASTER_SITES=	#

MAINTAINER=	dcarlier@deviceatlas.com
COMMENT=	DeviceAtlas Device Detection C API
WWW=		https://www.deviceatlas.com

LICENSE=	deviceatlas-enterprise-c-license
LICENSE_NAME=	DeviceAtlas C Enterprise API License
LICENSE_TEXT=	The free of charge offering has a restricted use license, for own usage only; \
		no redistribution or derivative works are permitted. \
		Contact us (http://www.deviceatlas.com/contact-us) to upgrade or to enable usage as part of a service offering.
LICENSE_PERMS=	none

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzip.so:archivers/libzip

USES=		cmake ssl zip
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DDOCSDIR=${DOCSDIR} -DEXAMPLESDIR=${EXAMPLESDIR}
PLIST_SUB=	PORTVERSION=${DISTVERSION}

REGISTRATION_URL=	https://deviceatlas.com/deviceatlas-haproxy-module

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=	you must manually fetch the DeviceAtlas Device Detection C API from ${REGISTRATION_URL} and place it in ${DISTDIR} and then run make again
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libda.so \
		${STAGEDIR}${PREFIX}/lib/libci.so \
		${STAGEDIR}${PREFIX}/bin/dajsonconv \
		${STAGEDIR}${PREFIX}/bin/dadwsch

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
