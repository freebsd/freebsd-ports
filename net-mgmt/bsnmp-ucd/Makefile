# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bsnmp-ucd
PORTVERSION=	0.4.0
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	A bsnmpd module that implements parts of UCD-SNMP-MIB

LICENSE=	BSD

MAKE_ENV+=	NO_OBJ=yes

post-patch:
	@${REINPLACE_CMD} -e '32,32 s/^.*/#include <sys\/queue.h>/' ${WRKSRC}/snmp_ucd.h

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/snmpd.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
