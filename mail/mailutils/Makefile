# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	mailutils
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailutils offers utilities and daemons for processing e-mail

DEPRECATED=	This port needs to be taken care of, it suffers from bit rot. \
Especially with options other than GUILE, uninstall may leave files behind

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS+=--disable-build-comsat
MAKE_JOBS_UNSAFE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

INFO=		${PORTNAME}
MAN1=		imap4d.1 mail.1 pop3d.1 popauth.1

OPTIONS_DEFINE=		GDBM BDB TOKYOCABINET GNUTLS MYSQL PGSQL LDAP PYTHON
OPTIONS_DEFINE+=	GUILE
OPTIONS_DEFAULT=
OPTIONS_SUB=		yes

GDBM_DESC=		Use GNU DBM
BDB_DESC=		Use Berkeley DB
TOKYOCABINET_DESC=	Use Tokyo Cabinet
GNUTLS_DESC=		Enable GNUTLS support
MYSQL_DESC=		Enable MySQL support
PGSQL_DESC=		Enable Postgres support
LDAP_DESC=		Enable LDAP support
PYTHON_DESC=		Enable Python support

GUILE_CONFIGURE_ON=	--with-guile
GUILE_CONFIGURE_OFF=	--without-guile
GUILE_LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=	--with-gdbm
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=		yes
CONFIGURE_ARGS+=	--with-berkeley-db
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if ${PORT_OPTIONS:MTOKYOCABINET}
CONFIGURE_ARGS+=	--with-tokyocabinet
LIB_DEPENDS+=		tokyocabinet:${PORTSDIR}/databases/tokyocabinet
PLIST_SUB+=		TOKYOCABINET=""
.else
CONFIGURE_ARGS+=	--without-tokyocabinet
PLIST_SUB+=		TOKYOCABINET="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python --with-pythondir=${PYTHON_SITELIBDIR}
USE_PYTHON=		yes
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
