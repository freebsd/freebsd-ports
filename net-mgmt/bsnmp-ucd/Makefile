# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bsnmp-ucd
PORTVERSION=	0.4.2
CATEGORIES=	net-mgmt

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	bsnmpd module that implements parts of UCD-SNMP-MIB

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	trociny

USES=		uidfix
MAKE_ENV+=	NO_OBJ=yes

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/snmpd.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
