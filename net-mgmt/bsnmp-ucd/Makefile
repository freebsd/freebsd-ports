PORTNAME=	bsnmp-ucd
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	bsnmpd module that implements parts of UCD-SNMP-MIB
WWW=		https://github.com/trociny/bsnmp-ucd

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	trociny

USES=		uidfix
MAKE_ENV+=	NO_OBJ=yes
MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/snmpd.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
