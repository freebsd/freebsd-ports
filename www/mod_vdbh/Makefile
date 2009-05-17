# New ports collection makefile for:	mod_vdbh
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_vdbh
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://www.synthemesc.com/downloads/mod_vdbh/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows mass virtual hosting using a MySQL backend with Apache 2.0.x

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
USE_MYSQL=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	AUTHORS README TODO

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
