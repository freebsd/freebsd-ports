# Created by: mbr@freebsd.org
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.0.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modauthmysql/modauthmysql/${PORTVERSION}
PKGNAMESUFFIX=	_another

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication


USE_MYSQL=	yes
USE_APACHE=	22

SHORTMODNAME=	mysql_auth
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/mysql
AP_LIB=	${LOCALBASE}/lib/mysql
AP_EXTRAS=	-lmysqlclient -lz -lm
AP_EXTRAS+=	-DAPACHE2

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|APR_XtOffsetOf|APR_OFFSETOF|g" \
		-e "s|APR_XtOffset|APR_OFFSET|g" ${WRKSRC}/mod_auth_mysql.c

.if !defined(NOPORTDOCS)
post-build:
	@${ECHO} "%%PORTDOCS%%%%DOCSDIR%%/CONFIGURE" >> ${PLIST}
	@${ECHO} "%%PORTDOCS%%%%DOCSDIR%%/CHANGES" >> ${PLIST}
	@${ECHO} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CONFIGURE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
