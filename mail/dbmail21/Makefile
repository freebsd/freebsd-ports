# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/tgz/
PKGNAMESUFFIX=	-${DATABASE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clement@FreeBSD.org
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
PORTDOCS=		INSTALL README

MAN1=			dbmail-adduser.1 dbmail-config.1 dbmail-imapd.1 \
			dbmail-maintenance.1 dbmail-pop3d.1 dbmail-smtp.1
MANCOMPRESSED=		no

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} "   By default dbmail uses MySQL backend database."
	@${ECHO} "   To build dbmail with PostgreSQL as backend database,"
	@${ECHO} "	define WITH_PGSQL"
	@${ECHO} ""

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | xargs ${RM} -fr

post-configure:
	@${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
				${WRKSRC}/dbmail.h

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
	@${MKDIR} ${DATADIR}/sql
	@${INSTALL_DATA} ${WRKSRC}/sql/${DATABASE}/* ${DATADIR}/sql
	@cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
