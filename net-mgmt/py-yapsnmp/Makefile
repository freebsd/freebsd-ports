# New ports collection makefile for:	py-yapsnmp
# Date created:				2005-01-07
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	yapsnmp
PORTVERSION=	0.7.8
PORTREVISION=	6
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Python SNMP module based on net-snmp

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

LICENSE=	LGPL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR}"  \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--enable-site-packages-prefix=${PREFIX}

post-patch:
	${REINPLACE_CMD} -e "s,-lsnmp,-lnetsnmp," \
		${WRKSRC}/configure

.include <bsd.port.mk>
