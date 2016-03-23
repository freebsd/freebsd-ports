# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bsnmp-ucd
PORTVERSION=	0.4.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://people.freebsd.org/~trociny/${PORTNAME}/

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	bsnmpd module that implements parts of UCD-SNMP-MIB

LICENSE=	BSD2CLAUSE

USES=		uidfix
MAKE_ENV+=	NO_OBJ=yes

post-patch:
	@${REINPLACE_CMD} -e '32,32 s/^.*/#include <sys\/queue.h>/' ${WRKSRC}/snmp_ucd.h

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/snmpd.config.sample ${STAGEDIR}${EXAMPLESDIR}

pre-build:
	${MAKE_CMD} -C ${WRKSRC} depend

.include <bsd.port.mk>
