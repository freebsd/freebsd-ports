# New ports collection makefile for: 	pmacct
# Date created:				Thu May  8 16:03:11 CEST 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	pmacct
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	http://www.ba.cnr.it/~paolo/pmacct/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network tool to gather IP traffic information

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--enable-mysql
CFLAGS+=	"-I${LOCALBASE}/include"
PLIST_SUB+=	WITH_MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--enable-pgsql
PLIST_SUB+=	WITH_PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e \
	's,<mysql/mysql.h>,<mysql.h>,' \
		${WRKSRC}/mysql_plugin.h
	@${REINPLACE_CMD} -e \
	's|-O2||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README EXAMPLES INTERNALS PLUGINS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
