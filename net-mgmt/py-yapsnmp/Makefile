# New ports collection makefile for:	py-yapsnmp
# Date created:				2005-01-07
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	yapsnmp
PORTVERSION=	0.7.8
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	yapsnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Python SNMP module based on net-snmp

LIB_DEPENDS=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e "s,-lsnmp,-lnetsnmp," \
		${WRKSRC}/configure

.include <bsd.port.mk>
