PORTNAME=	dbmail
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.4
CATEGORIES=	mail

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SQL database-based mail system (POP3 and IMAP)
WWW=		http://www.dbmail.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		docbook-sgml>0:textproc/docbook-sgml \
		xmlto:textproc/xmlto
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libgmime-3.0.so:mail/gmime30 \
		libmhash.so:security/mhash \
		libzdb.so:databases/libzdb

USES=		autoreconf gmake gnome libtool localbase pkgconfig shebangfix \
		ssl
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
SHEBANG_FILES=	man/fixsp.pl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-manpages \
			--sysconfdir=${LOCALBASE}/etc \
			--with-zdb=${LOCALBASE}

INSTALL_TARGET=	install-strip

PLIST_SUB+=	DBMAIL_GROUP="${DBMAIL_GROUP}" \
		DBMAIL_USER="${DBMAIL_USER}" \
		PIDDIR="${PIDDIR}"

OPTIONS_DEFINE=		DOCS LDAP SIEVE
OPTIONS_DEFAULT=	SIEVE
OPTIONS_SUB=		yes

SIEVE_DESC=		Sieve mail sorting language support

DOCS=		AUTHORS CHANGELOG.md INSTALL README THANKS UPGRADING
LDAP_USES=		gettext-runtime ldap
LDAP_CONFIGURE_WITH=	ldap
SIEVE_LIB_DEPENDS=	libsieve.so:mail/libsieve
SIEVE_CONFIGURE_WITH=	sieve

DBMAIL_USER?=	mailnull
DBMAIL_GROUP?=	mail
PIDDIR?=	/var/run/dbmail

post-patch:
	@${REINPLACE_CMD} -e '/dbmail-sieved\.8 /d' \
		${WRKSRC}/man/Makefile.am \
		${WRKSRC}/man/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${STAGEDIR}${PREFIX}/etc/dbmail.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dbmail.schema ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/sql && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${PIDDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
