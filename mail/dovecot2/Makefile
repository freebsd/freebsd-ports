# Created by: Nagy, Attila <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	dovecot
PORTVERSION=	2.2.15
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${PORTVERSION:R}/
PKGNAMESUFFIX=	2

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Secure, fast and powerful IMAP and POP3 server

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

USES=		cpe iconv libtool
USE_RC_SUBR=	dovecot
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-statedir=/var/db/dovecot \
		--without-shadow

USE_LDCONFIG=	${PREFIX}/lib/dovecot
INSTALL_TARGET=	install-strip

USERS=		dovecot dovenull
GROUPS=		${USERS}

OPTIONS_DEFINE=	KQUEUE SSL VPOPMAIL LDAP LUCENE LZ4 PGSQL MYSQL SQLITE \
		SOLR DOCS EXAMPLES LIBWRAP
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=KQUEUE SSL GSSAPI_NONE
OPTIONS_SUB=	yes

KQUEUE_DESC=	kqueue(2) support
LUCENE_DESC=	CLucene FTS support
LZ4_DESC=	LZ4 compression support
SOLR_DESC=	Solr FTS support
VPOPMAIL_DESC=	vpopmail support

GSSAPI_NONE_DESC=	Build without GSSAPI support
GSSAPI_BASE_DESC=	Use GSSAPI from base
GSSAPI_HEIMDAL_DESC=	Use Heimdal GSSAPI from security/heimdal
GSSAPI_MIT_DESC=	Use MIT GSSAPI from security/krb5

DOCS_CONFIGURE_WITH=	docs

GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi ${GSSAPI_CONFIGURE_ARGS}

KQUEUE_CONFIGURE_OFF=	--with-ioloop=poll
KQUEUE_CONFIGURE_ON=	--with-ioloop=kqueue

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
LDAP_RC_REQUIRE=	slapd

LIBWRAP_CONFIGURE_WITH=	libwrap

LUCENE_CONFIGURE_WITH=	lucene
LUCENE_LIB_DEPENDS=	libclucene-core.so:${PORTSDIR}/textproc/clucene

LZ4_LIB_DEPENDS=	liblz4.so:${PORTSDIR}/archivers/liblz4

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_RC_REQUIRE=	mysql

PGSQL_USE=		PGSQL=yes
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_RC_REQUIRE=	postgresql

SOLR_CONFIGURE_WITH=	solr
SOLR_BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
SOLR_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

SQLITE_USE=		SQLITE=3
SQLITE_CONFIGURE_WITH=	sqlite

SSL_CONFIGURE_WITH=	ssl=openssl

VPOPMAIL_BUILD_DEPENDS=	${LOCALBASE}/vpopmail/bin/vchkpw:${PORTSDIR}/mail/vpopmail
VPOPMAIL_CONFIGURE_WITH=vpopmail

DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not build on arm
.endif

CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -I${OPENSSLLIB}

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

.for opt in ${PORT_OPTIONS}
_REQUIRE+=	${${opt}_RC_REQUIRE}
.endfor

SUB_LIST+=	REQUIRE="${_REQUIRE}"
SUB_FILES+=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dovecot,${PREFIX}/etc/dovecot,g; \
		s,sysconfdir=/etc,sysconfdir=${PREFIX}/etc,g' \
		${WRKSRC}/doc/example-config/*.conf ${WRKSRC}/doc/example-config/conf.d/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
