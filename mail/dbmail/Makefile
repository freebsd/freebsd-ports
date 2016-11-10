# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dbmail
PORTVERSION=	3.2.3
CATEGORIES=	mail
MASTER_SITES=	http://git.dbmail.eu/paul/dbmail/snapshot/ \
		http://www.dbmail.org/download/3.2/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SQL database-based mail system (POP3 and IMAP)

LICENSE=	GPLv2

LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libzdb.so:databases/libzdb \
		libmhash.so:security/mhash \
		libevent.so:devel/libevent2
BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto \
		docbook-sgml>0:textproc/docbook-sgml

BROKEN_aarch64=	Fails to link: missing sbrk

CONFLICTS=	dbmail22-[0-9]*

OPTIONS_DEFINE=	DOCS LDAP SIEVE
OPTIONS_DEFAULT=	SIEVE
SIEVE_DESC=	Sieve mail sorting language support

OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip
USE_AUTOTOOLS=	autoheader autoconf
USE_LDCONFIG=	${PREFIX}/lib/dbmail
USE_RC_SUBR=	dbmail-pop3d dbmail-lmtpd dbmail-imapd dbmail-timsieved
USE_OPENSSL=	yes
USES=		gmake libtool pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	man/fixsp.pl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-zdb=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc --enable-manpages

MAKE_ARGS+=	mandir=${MANPREFIX}/man

DOCS=		AUTHORS BUGS INSTALL THANKS UPGRADING

SIEVE_CONFIGURE_WITH=	sieve
SIEVE_LIB_DEPENDS=	libsieve.so:mail/libsieve

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

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
