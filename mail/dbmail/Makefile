# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	3.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libzdb.so:databases/libzdb \
		libmhash.so:security/mhash \
		libevent.so:devel/libevent
BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto \
		docbook-sgml>0:textproc/docbook-sgml

USES=		autoreconf gmake gnome libtool localbase pkgconfig shebangfix ssl
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved

CONFLICTS=	dbmail22-[0-9]*

GH_ACCOUNT=	dbmail

OPTIONS_DEFINE=	DOCS LDAP SIEVE
OPTIONS_DEFAULT=	SIEVE
OPTIONS_SUB=	yes
SIEVE_DESC=	Sieve mail sorting language support

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes

SHEBANG_FILES=	man/fixsp.pl

CONFIGURE_ARGS+=	--with-zdb=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc --enable-manpages

MAKE_ARGS+=	mandir=${MANPREFIX}/man

DOCS=		AUTHORS CHANGELOG.md INSTALL README THANKS UPGRADING

SIEVE_CONFIGURE_WITH=	sieve
SIEVE_LIB_DEPENDS=	libsieve.so:mail/libsieve

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes
LDAP_USES=		gettext-runtime

DBMAIL_USER?=	mailnull
DBMAIL_GROUP?=	mail
PIDDIR?=	/var/run/dbmail

PLIST_SUB+=	DBMAIL_USER="${DBMAIL_USER}" \
		DBMAIL_GROUP="${DBMAIL_GROUP}" \
		PIDDIR="${PIDDIR}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${STAGEDIR}${PREFIX}/etc/dbmail.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dbmail.schema ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/sql && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${PIDDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
