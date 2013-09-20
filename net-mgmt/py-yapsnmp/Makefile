# Created by: arved
# $FreeBSD$

PORTNAME=	yapsnmp
PORTVERSION=	0.7.8
PORTREVISION=	7
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Python SNMP module based on net-snmp

LIB_DEPENDS=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-site-packages-prefix=${PREFIX}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 800000) && (${ARCH} == "i386")
CPPFLAGS+=	-fstack-protector -I${LOCALBASE}/include
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lsnmp,-lnetsnmp," \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
