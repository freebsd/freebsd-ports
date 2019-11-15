# Created by: mbr@FreeBSD.org
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.0.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/modauthmysql/modauthmysql/${PORTVERSION}
PKGNAMESUFFIX=	_another

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

LICENSE=	APACHE10

USES=		apache:2.2+ mysql

SHORTMODNAME=	mysql_auth
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/mysql
AP_LIB=	${LOCALBASE}/lib/mysql
AP_EXTRAS=	-lmysqlclient_r -lz -lm

PORTDOCS=	CONFIGURE CHANGES

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
