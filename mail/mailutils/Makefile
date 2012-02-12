# New ports collection makefile for:	mailutils
# Date created:				2011-07-05
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	mailutils
PORTVERSION=	2.2
CATEGORIES=	mail
MASTER_SITES=	GNU

MAINTAINER=	bra@fsn.hu
COMMENT=	Mailutils offers utilities and daemons for processing e-mail

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS+=--disable-build-comsat

LDFLAGS=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

INFO=		${PORTNAME}
MAN1=		imap4d.1 mail.1 pop3d.1 popauth.1

OPTIONS=	GDBM		"Use GNU DBM"			Off \
		BDB		"Use Berkeley DB"		Off \
		TOKYOCABINET	"Use Tokyo Cabinet"		Off \
		GNUTLS		"Enable GNUTLS support"		Off \
		MYSQL		"Enable MySQL support"		Off \
		PGSQL		"Enable Postgres support"	Off \
		LDAP		"Enable LDAP support"		Off \
		PYTHON		"Enable Python support"		Off

.include <bsd.port.options.mk>

.if defined(WITH_GDBM)
CONFIGURE_ARGS+=	--with-gdbm
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if defined(WITH_BDB)
USE_BDB=		yes
CONFIGURE_ARGS+=	--with-berkeley-db
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if defined(WITH_TOKYOCABINET)
CONFIGURE_ARGS+=	--with-tokyocabinet
LIB_DEPENDS+=		tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet
PLIST_SUB+=		TOKYOCABINET=""
.else
CONFIGURE_ARGS+=	--without-tokyocabinet
PLIST_SUB+=		TOKYOCABINET="@comment "
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python --with-pythondir=${PYTHON_SITELIBDIR}
USE_PYTHON=		2.5+
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
