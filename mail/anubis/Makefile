PORTNAME=	anubis
PORTVERSION=	4.3
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	GNU

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Outgoing SMTP mail processor
WWW=		https://www.gnu.org/software/anubis/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgsasl.so:security/libgsasl

USES=		autoreconf charsetfix cpe gettext-tools gmake localbase \
		makeinfo pkgconfig shebangfix
CHARSETFIX_MAKEFILEIN=	gnulib.mk
CPE_VENDOR=	gnu
SHEBANG_FILES=	contrib/msg2smtp.pl
USE_RC_SUBR=	anubis

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-gnutls \
		--with-gsasl

INFO=		anubis
PORTEXAMPLES=	1anubisrc 2anubisrc

OPTIONS_DEFINE=		NLS EXAMPLES EMACS GUILE GNUPG LIBWRAP PCRE PAM \
			SOCKS TEST
DB_DESC=		Database backend
OPTIONS_GROUP=		DB
OPTIONS_GROUP_DB=	GDBM MYSQL PGSQL
OPTIONS_DEFAULT=	GDBM GNUPG GUILE
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

.if !exists(/usr/include/tcpd.h)
OPTIONS_EXCLUDE+=	LIBWRAP
.endif
.if !exists(/usr/lib/libpam.so)
OPTIONS_EXCLUDE+=	PAM
.endif

EMACS_DESC=		Install EMACS lisp files (requires emacs)
EMACS_USES=		emacs:build
EMACS_CONFIGURE_ON=	--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}/anubis
EMACS_CONFIGURE_OFF=	--with-lispdir=no

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme
GNUPG_CONFIGURE_WITH=	gpgme

GUILE_USES=		guile:2.2,alias
GUILE_CONFIGURE_WITH=	guile
GUILE_PORTEXAMPLES=	anubis.scm anubisrc.guile

LIBWRAP_CONFIGURE_WITH=	tcp-wrappers

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_VARS=		REQUIRE+=mysql

NLS_CONFIGURE_ENABLE=	nls

PAM_CONFIGURE_WITH=	pam
PAM_PORTEXAMPLES=	pam

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgres
PGSQL_VARS=		REQUIRE+=postgresql

SOCKS_CONFIGURE_WITH=	socks-proxy

TEST_TEST_TARGET=	check

.include <bsd.port.options.mk>

# Default requirement for anubis rc script
REQUIRE+=	mail
SUB_LIST+=	REQUIRE="${REQUIRE}"

post-patch-TEST-off:
	@${REINPLACE_CMD} -e 's| tests||' ${WRKSRC}/Makefile.am

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*rc ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MGUILE}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${GUILE_PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MPAM}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pam
	${INSTALL_DATA} ${WRKSRC}/examples/pam/anubis* ${STAGEDIR}${EXAMPLESDIR}/pam
.endif

.include <bsd.port.mk>
