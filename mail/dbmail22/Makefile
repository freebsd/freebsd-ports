# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	1.2.1
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/tgz/
PKGNAMESUFFIX=	-${DATABASE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	An SQL database-based mail system (POP3 and IMAP)

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	YES
USE_OPENSSL=	YES

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql-client
DATABASE=		postgresql
PLIST_SUB+=		PGSQL=""
PLIST_SUB+=		MYSQL="@comment "
LDFLAGS+=		-L${LOCALBASE}/lib/
.else
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
DATABASE=		mysql
PLIST_SUB+=		MYSQL=""
PLIST_SUB+=		PGSQL="@comment "
CFLAGS+=		-I${LOCALBASE}/include/mysql
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}" LOCALBASE=${LOCALBASE}
FILES_TO_PATCH=		imapd.c main.c maintenance.c pop3d.c user.c
DOCS=			INSTALL README

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} "   By default dbmail uses MySQL backend database."
	@${ECHO} "   To build dbmail with PostgreSQL as backend database,"
	@${ECHO} "	define WITH_PGSQL"
	@${ECHO} ""

post-configure:
.for FILE in ${FILES_TO_PATCH}
	@${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
				${WRKSRC}/${FILE}
.endfor

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
	@${MKDIR} ${DATADIR}/sql
	@${INSTALL_DATA} ${WRKSRC}/sql/${DATABASE}/* ${DATADIR}/sql
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
