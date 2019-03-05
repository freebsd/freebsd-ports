# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	2.2.18
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/2.2/
PKGNAMESUFFIX=	22

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

DEPRECATED=	Please use mail/dbmail which uses latest version of 3.X
EXPIRATION_DATE=	2019-04-04

LIB_DEPENDS=	libgmime-2.0.so:mail/gmime2

USES=		gmake gnome libtool pkgconfig ssl
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_GNOME=	glib20

CONFLICTS=	dbmail-3.*

OPTIONS_DEFINE=	DOCS LDAP SIEVE
OPTIONS_DEFAULT=MYSQL
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=MYSQL PGSQL SQLITE
SIEVE_DESC=	Support for Sieve mail sorting language

OPTIONS_SUB=	yes

MYSQL_USES=	mysql
MYSQL_CONFIGURE_WITH=	mysql
SQLITE_USES=	sqlite:3
SQLITE_CONFIGURE_WITH=	sqlite
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	pgsql
SIEVE_CONFIGURE_WITH=	sieve
SIEVE_LIB_DEPENDS=	libsieve.so:mail/libsieve
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CONFIGURE_ARGS+=	--with-pkglibdir=${LOCALBASE}/lib/dbmail
MAKE_ARGS+=	mandir=${MANPREFIX}/man

PORTDOCS=	AUTHORS BUGS COPYING INSTALL NEWS README \
		README.aliases README.exim README.ldap \
		README.postfix README.qmail README.sieve \
		README.smtp README.solaris README.usermap \
		THANKS
SUB_FILES=	pkg-message

PLIST_SUB+=	PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
DATABASE+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
DATABASE+=	postgresql
.endif

.if ${PORT_OPTIONS:MSQLITE}
DATABASE+=	sqlite
.endif

post-configure:
	${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
				${WRKSRC}/dbmail.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${STAGEDIR}${PREFIX}/etc/dbmail.conf-dist
	${MKDIR} ${STAGEDIR}${DATADIR}
	for f in ${DATABASE}; do \
	  ${MKDIR} ${STAGEDIR}${DATADIR}/$$f ; \
	  ${INSTALL_DATA} ${WRKSRC}/sql/$$f/* ${STAGEDIR}${DATADIR}/$$f; \
	done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
