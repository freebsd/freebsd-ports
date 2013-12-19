# Created by: mbr@FreeBSD.org
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.0.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modauthmysql/modauthmysql/${PORTVERSION}
PKGNAMESUFFIX=	_another

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

#LICENSE=	AL10

USE_MYSQL=	yes
USE_APACHE=	22

SHORTMODNAME=	mysql_auth
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/mysql
AP_LIB=	${LOCALBASE}/lib/mysql
AP_EXTRAS=	-lmysqlclient -lz -lm
AP_EXTRAS+=	-DAPACHE2

PORTDOCS=	CONFIGURE CHANGES

post-patch:
	${REINPLACE_CMD} -e "s|APR_XtOffsetOf|APR_OFFSETOF|g" \
		-e "s|APR_XtOffset|APR_OFFSET|g" ${WRKSRC}/mod_auth_mysql.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
