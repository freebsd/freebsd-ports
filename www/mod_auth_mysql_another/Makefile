# New ports collection makefile for:    apache mod_auth_mysql_another
# Date created:		2002/04/20
# Whom:			mbr@freebsd.org
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_//g}
PKGNAMESUFFIX=	_another

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

USE_MYSQL=	YES

SHORTMODNAME=	mysql_auth
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC=		${LOCALBASE}/include/mysql
AP_LIB=		${LOCALBASE}/lib/mysql
AP_EXTRAS=	-DAPACHE${AP_VER} -lmysqlclient -lz -lm

.include <bsd.port.pre.mk>

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

.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"
.include <bsd.port.post.mk>
