# Created by: Nagy, Attila <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	dovecot
PORTVERSION=	2.2.13
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${PORTVERSION:R}/
PKGNAMESUFFIX=	2

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Secure and compact IMAP and POP3 servers

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual

CONFLICTS=	dovecot-1.[0-9]*

######################################################################
# Anytime PORTVERSION changes please bump PORTREVISION of            #
# mail/dovecot2-pigeonhole and also mail/dovecot2-antispam-plugin.   #
# Please see ports/135311 and ports/146029 for an explanation.       #
#                                                                    #
# Please be careful when updating this port as changes to this port  #
# can break mail/dovecot2-pigeonhole. In order to ensure the least   #
# amount of breakage possible please consult the maintainer of that  #
# port before updating this one.                                     #
######################################################################

USES=		iconv
USE_RC_SUBR=	dovecot

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-statedir=/var/db/dovecot \
		--without-shadow

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	${PREFIX}/lib/dovecot
INSTALL_TARGET=	install-strip

USERS=		dovecot dovenull
GROUPS=		${USERS}

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

OPTIONS_DEFINE=	KQUEUE SSL GSSAPI VPOPMAIL LDAP LUCENE PGSQL MYSQL SQLITE \
		SOLR DOCS EXAMPLES LIBWRAP
OPTIONS_DEFAULT=KQUEUE SSL
OPTIONS_SUB=	yes

KQUEUE_DESC=	kqueue(2) support
VPOPMAIL_DESC=	vpopmail support
LUCENE_DESC=	CLucene FTS support
SOLR_DESC=	Solr FTS support

DOCS_CONFIGURE_WITH=	docs

GSSAPI_CONFIGURE_WITH=	gssapi
GSSAPI_LDFLAGS=		-lgssapi_krb5

KQUEUE_CONFIGURE_OFF=	--with-ioloop=poll
KQUEUE_CONFIGURE_ON=	--with-ioloop=kqueue

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes

LIBWRAP_CONFIGURE_WITH=	libwrap

LUCENE_CONFIGURE_WITH=	lucene
LUCENE_LIB_DEPENDS=	libclucene-core.so:${PORTSDIR}/textproc/clucene

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		MYSQL=yes

PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USE=		PGSQL=yes

SOLR_BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
SOLR_CONFIGURE_WITH=	solr
SOLR_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_USE=		SQLITE=3

SSL_CONFIGURE_OFF=	--without-ssl
SSL_CONFIGURE_ON=	--with-ssl=openssl

VPOPMAIL_BUILD_DEPENDS=	${LOCALBASE}/vpopmail/bin/vchkpw:${PORTSDIR}/mail/vpopmail
VPOPMAIL_CONFIGURE_WITH=vpopmail

DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not build on arm
.endif

.if ${PORT_OPTIONS:MLDAP}
_REQUIRE+=	slapd
.endif

.if ${PORT_OPTIONS:MPGSQL}
_REQUIRE+=	postgresql
.endif

.if ${PORT_OPTIONS:MMYSQL}
_REQUIRE+=	mysql
.endif

SUB_LIST+=	REQUIRE="${_REQUIRE}"
SUB_FILES+=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dovecot,${PREFIX}/etc/dovecot,g; \
		s,sysconfdir=/etc,sysconfdir=${PREFIX}/etc,g' \
		${WRKSRC}/doc/example-config/*.conf ${WRKSRC}/doc/example-config/conf.d/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
