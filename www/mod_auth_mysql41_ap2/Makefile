# New ports collection makefile for:	mod_auth_mysql41_ap2
# Date Created:				Thu Oct  2 10:33:50 CDT 2003
# Whom:					Douglas A. Maske <maske@maske.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_mysql41_ap2
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# no longer accessible
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL 4.1 and Apache 2 port of mod_auth_mysql

DEPRECATED=		distfile no longer fetchable
EXPIRATION_DATE=	2009-10-17

MAKE_JOBS_SAFE=  yes

USE_MYSQL=	YES
WANT_MYSQL_VER=	41

USE_APACHE=	2.0
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include/mysql
AP_LIB=	${LOCALBASE}/lib/mysql -lmysqlclient
AP_EXTRAS=	-DAPACHE2

MODULENAME=	mod_auth_mysql

SUB_FILES+=	pkg-message

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
