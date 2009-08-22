# New ports collection makefile for:    apache mod_auth_mysql
# Date created:		2000/05/19
# Whom:			jim@thehouselys.net
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	SF/mod-auth-mysql/mod-auth-mysql/mod-auth-mysql-1.0

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/${APACHE_PORT}

MAKE_JOBS_SAFE=  yes

USE_MYSQL=	yes

USE_APACHE=	13
AP_GENPLIST=	yes
PORTDOCS=	README USAGE
PLIST_FILES+=	libexec/apache/mod_auth_mysql.so

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},g' -e 's,apxs,${APXS},' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
