# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	2.2.18
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/2.2/
PKGNAMESUFFIX=	22

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

LIB_DEPENDS=	gmime-2.0:${PORTSDIR}/mail/gmime2

CONFLICTS=	dbmail-3.*

OPTIONS_DEFINE=	SIEVE LDAP
OPTIONS_DEFAULT=MYSQL
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=MYSQL PGSQL SQLITE
SIEVE_DESC=	Support for Sieve mail sorting language

LATEST_LINK=	dbmail22
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_GNOME=	glib20
USE_OPENSSL=	yes
USES=		pkgconfig

CFLAGS+=	-fPIC -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
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
SUB_FILES=	pkg-message

PLIST_SUB+=	PORTNAME=${PORTNAME}
.if empty(PORT_OPTIONS:MDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.else
PLIST_SUB+=	PORTDOCS=""
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=--with-mysql
USE_MYSQL=	yes
DATABASE+=	mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=--with-pgsql
USE_PGSQL=	yes
DATABASE+=	postgresql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=--with-sqlite
USE_SQLITE=	yes
DATABASE+=	sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MSIEVE}
CONFIGURE_ARGS+=--with-sieve=${LOCALBASE}/include
LIB_DEPENDS+=	sieve:${PORTSDIR}/mail/libsieve
PLIST_SUB+=	SIEVE=""
.else
PLIST_SUB+=	SIEVE="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-auth-ldap=${LOCALBASE}/include
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -fr
	@${FIND} ${WRKSRC} -name *.orig -type f -delete

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
