# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	xml-security-c
PORTVERSION=	1.6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=santuario/c-library
PKGNAMEPREFIX=	apache-

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Apache XML security libraries - C++ version

LICENSE=	AL2

OPTIONS_DEFINE=		XERCES_3
OPTIONS_DEFAULT=	XERCES_3

XERCES_3_DESC=		With Xerces vesion 3.x (shibboleth2 requires)

USE_OPENSSL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXERCES_3}
LIB_DEPENDS+=	xerces-c.3:${PORTSDIR}/textproc/xerces-c3
.else
LIB_DEPENDS+=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
