# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/
PKGNAMESUFFIX=	-${DATABASE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	An SQL database-based mail system (POP3 and IMAP)

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	YES
USE_OPENSSL=	YES

CFLAGS += -fPIC

SED_SCRIPT+=    -e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-pgsql
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql7
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
PORTDOCS=		INSTALL README EXTRAS

MAN1=			dbmail-smtp.1
MAN8=			dbmail-imapd.8 dbmail-lmtpd.8 dbmail-pop3d.8 \
			dbmail-users.8 dbmail-util.8
MANCOMPRESSED=		no

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} "   By default dbmail uses MySQL backend database."
	@${ECHO} "   To build dbmail with PostgreSQL as backend database,"
	@${ECHO} "	define WITH_POSTGRESQL"
	@${ECHO} ""

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | xargs ${RM} -fr

post-configure:
	@${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
				${WRKSRC}/dbmail.h

post-build:
.for f in imap lmtp pop3
	@${SED} ${SED_SCRIPT} ${FILESDIR}/dbmail-${f}d.sh > ${WRKDIR}/dbmail-${f}d.sh
.endfor

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
.for f in imap lmtp pop3
	@${INSTALL_SCRIPT} ${WRKDIR}/dbmail-${f}d.sh ${DESTDIR}${PREFIX}/etc/rc.d/dbmail-${f}d.sh
.endfor
	@${MKDIR} ${DATADIR}/sql
	@${INSTALL_DATA} ${WRKSRC}/sql/${DATABASE}/* ${DATADIR}/sql
	@cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${ECHO} ""
	@${ECHO} "IMPORTANT NOTE FOR ADMINS UPGRADING FROM 1.X->2.X!!!"
	@${ECHO} ""
	@${ECHO} "	*) Don't forget to update the database using a script from"
	@${ECHO} "	   ${DATADIR}/sql/"
	@${ECHO} "	*) Many programs have been renamed and their arguments changed."
	@${ECHO} "	*) Read the upgrading notes."
	@${ECHO} "	*) Don't be careless with this upgrade or mail will be lost!"
	@${ECHO} "	*) dbmail can be controled by setting dbmail_imapd_enable,"
	@${ECHO} "	   dbmail_lmtpd_enable, and/or dbmail_pop3d_enable in"
	@${ECHO} "	   /etc/rc.conf."
	@${ECHO} ""


.include <bsd.port.mk>
