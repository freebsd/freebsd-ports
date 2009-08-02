# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	2.2.11
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/2.2/

MAINTAINER=	mark_sf@kikg.ifmo.ru
COMMENT=	An SQL database-based mail system (POP3 and IMAP)

LIB_DEPENDS=	gmime-2.0.4:${PORTSDIR}/mail/gmime2

CONFLICTS=	dbmail-*-2.0.* dbmail-2.1.*

OPTIONS=	MYSQL		"Build with MySQL support" on \
		POSTGRESQL	"Build with PostgreSQL support"	off \
		SQLITE		"Build with SQLite support" off \
		SIEVE		"Build w. support for Sieve mail sorting language" off \
		LDAP		"Build with support for LDAP authentication" off

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	YES
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d.sh dbmail-lmtpd.sh dbmail-imapd.sh dbmail-timsieved.sh
USE_GNOME=	glib20 pkgconfig
USE_OPENSSL=	YES

CFLAGS+=	-fPIC -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" LOCALBASE=${LOCALBASE}
CONFIGURE_ARGS+=	--with-pkglibdir=${LOCALBASE}/lib/dbmail
MAKE_ARGS+=	mandir=${MANPREFIX}/man

PORTDOCS=	AUTHORS BUGS COPYING INSTALL NEWS README \
		README.aliases README.exim README.ldap \
		README.postfix README.qmail README.sieve \
		README.smtp README.solaris README.usermap \
		THANKS
MAN1=		dbmail-smtp.1 dbmail.1
MAN5=		dbmail.conf.5
MAN8=		dbmail-export.8 dbmail-imapd.8 dbmail-lmtpd.8 \
		dbmail-pop3d.8 dbmail-sievecmd.8 dbmail-timsieved.8 \
		dbmail-users.8 dbmail-util.8
MANCOMPRESSED=	no
SUB_FILES=	pkg-message

PLIST_SUB+=	PORTNAME=${PORTNAME}
.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.else
PLIST_SUB+=	PORTDOCS=""
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=--with-mysql
USE_MYSQL=	YES
DATABASE+=	mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=--with-pgsql
USE_PGSQL=	yes
DATABASE+=	postgresql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=--with-sqlite
USE_SQLITE=	yes
DATABASE+=	sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_SIEVE)
CONFIGURE_ARGS+=--with-sieve=${LOCALBASE}/include
LIB_DEPENDS+=	sieve.1:${PORTSDIR}/mail/libsieve
PLIST_SUB+=	SIEVE=""
.else
PLIST_SUB+=	SIEVE="@comment "
.endif

.if defined(WITH_LDAP)
CONFIGURE_ARGS+=--with-auth-ldap=${LOCALBASE}/include
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITHOUT_MYSQL) && !defined(WITH_POSTGRESQL) && !defined(WITH_SQLITE)
IGNORE="requires at least one database backend selected. Run 'make config'"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -fr
	@${FIND} ${WRKSRC} -name *.orig -type f | ${XARGS} ${RM} -fr

post-configure:
	@${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
				${WRKSRC}/dbmail.h

# remove leftovers which are not removed by some revisions of port
# fixes the `Shared object "libpgsqldbmail.so.0" not found, required by "libdbmail.so.0"' error.
pre-install:
	@for f in 'a' 'la' 'so' 'so.0'; do \
	  if [ -f ${PREFIX}/lib/libdbmail.$$f ] ; then \
	    ${RM} ${PREFIX}/lib/libdbmail.$$f; \
	  fi; \
	done

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
	@if [ ! -f ${PREFIX}/etc/dbmail.conf ] ; then \
	  ${CP} -p ${PREFIX}/etc/dbmail.conf-dist ${PREFIX}/etc/dbmail.conf; \
	fi
	@${MKDIR} ${DATADIR}
	@for f in ${DATABASE}; do \
	  ${MKDIR} ${DATADIR}/$$f ; \
	  ${INSTALL_DATA} ${WRKSRC}/sql/$$f/* ${DATADIR}/$$f; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
