# Created by: David Carlier
# $FreeBSD$

PORTNAME=	deviceatlas-enterprise-c
PORTVERSION=	2.3.4
CATEGORIES=	net devel
MASTER_SITES=	#

MAINTAINER=	dcarlier@afilias.info
COMMENT=	DeviceAtlas Device Detection C API

LICENSE=	deviceatlas-enterprise-c-license
LICENSE_NAME=	DeviceAtlas C Enterprise API License
LICENSE_TEXT=	The free of charge offering has a restricted use license, for own usage only; \
		no redistribution or derivative works are permitted. \
		Contact us (http://www.deviceatlas.com/contact-us) to upgrade or to enable usage as part of a service offering.
LICENSE_PERMS=	none

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake zip
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DDOCSDIR=${DOCSDIR} -DEXAMPLESDIR=${EXAMPLESDIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

REGISTRATION_URL=	https://deviceatlas.com/deviceatlas-haproxy-module

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=	you must manually fetch the DeviceAtlas Device Detection C API from ${REGISTRATION_URL} and place it in ${DISTDIR} and then run make again
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libda.so \
		${STAGEDIR}${PREFIX}/lib/libci.so

.include <bsd.port.post.mk>
