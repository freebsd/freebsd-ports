# New ports collection makefile for: 	pmacct
# Date created:				Thu May  8 16:03:11 CEST 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	pmacct
PORTVERSION=	0.4.2
CATEGORIES=	net
MASTER_SITES=	http://www.ba.cnr.it/~paolo/pmacct/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network tool to gather IP traffic information

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--enable-mysql
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \

pre-patch:
		@${REINPLACE_CMD} -e \
		's,<mysql/mysql.h>,<mysql.h>,' \
			${WRKSRC}/mysql_plugin.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README EXAMPLES INTERNALS PLUGINS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
