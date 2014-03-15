# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
PORTREVISION=	4
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

LATEST_LINK=	mod_log_sql2
GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2
CONFIGURE_ARGS+=	--with-apxs=${APXS}
SSL_PLIST=	""
APACHE2X=	""
PLIST_SUB+=	SSL=${SSL_PLIST} APACHE2X=${APACHE2X}

USE_MYSQL=	yes
USE_APACHE=	22
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"

.include <bsd.port.pre.mk>

.if defined(WITH_DBI) || exists(${LOCALBASE}/include/dbi/dbi.h)
CONFIGURE_ARGS+=	--with-dbi=${LOCALBASE}
LIB_DEPENDS+=		libdbi.so:${PORTSDIR}/databases/libdbi
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
SSL_PLIST=	"@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.post.mk>
