# Created by: ijliao
# $FreeBSD$

PORTNAME=	anubis
PORTVERSION=	4.2
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	GNU

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Outgoing SMTP mail processor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf charsetfix cpe localbase makeinfo \
		pkgconfig shebangfix
CHARSETFIX_MAKEFILEIN=	gnulib.mk
CPE_VENDOR=	gnu
SHEBANG_FILES=	contrib/msg2smtp.pl
USE_RC_SUBR=	anubis
GNU_CONFIGURE=	yes

INFO=		anubis
PORTEXAMPLES=	1anubisrc 2anubisrc

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		NLS EXAMPLES EMACS GUILE GNUPG GNUTLS \
			GSASL LIBWRAP PCRE PAM SOCKS TEST
OPTIONS_GROUP=		DB
OPTIONS_GROUP_DB=	GDBM MYSQL PGSQL
OPTIONS_DEFAULT=	GUILE GNUPG GNUTLS GSASL
OPTIONS_EXCLUDE_aarch64=TEST
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

.if !exists(/usr/include/tcpd.h)
OPTIONS_EXCLUDE+=	LIBWRAP
.endif
.if !exists(/usr/lib/libpam.so)
OPTIONS_EXCLUDE+=	PAM
.endif

EMACS_DESC=		Install EMACS lisp files (requires emacs)
EMACS_USE=		EMACS=yes
EMACS_CONFIGURE_ON=	--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}/anubis
EMACS_CONFIGURE_OFF=	--with-lispdir=no

GDBM_DESC=		GDBM backend
GDBM_IMPLIES=		GSASL
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

GNUPG_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libgpg-error.so:security/libgpg-error
GNUPG_CONFIGURE_WITH=	gpgme

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt
GNUTLS_CONFIGURE_WITH=	gnutls

GSASL_DESC=		GSASL support (required for databases)
GSASL_LIB_DEPENDS=	libgsasl.so:security/gsasl
GSASL_CONFIGURE_WITH=	gsasl

GUILE_LIB_DEPENDS=	libltdl.so:devel/libltdl \
			libguile.so:lang/guile \
			libgmp.so:math/gmp
GUILE_CONFIGURE_WITH=	guile
GUILE_PORTEXAMPLES=	anubis.scm anubisrc.guile

LIBWRAP_CONFIGURE_WITH=	tcp-wrappers

MYSQL_IMPLIES=		GSASL
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_VARS=		REQUIRE+=mysql

NLS_USES=		gettext iconv
NLS_CONFIGURE_ENABLE=	nls

PAM_CONFIGURE_WITH=	pam
PAM_PORTEXAMPLES=	pam

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

PGSQL_IMPLIES=		GSASL
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgres
PGSQL_VARS=		REQUIRE+=postgresql

SOCKS_DESC=		SOCKS proxy support
SOCKS_CONFIGURE_WITH=	socks-proxy

.include <bsd.port.options.mk>

# Default requirement for anubis rc script
REQUIRE+=	mail
SUB_LIST+=	REQUIRE="${REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h

post-patch-TEST-off:
	@${REINPLACE_CMD} -e 's| testsuite||' ${WRKSRC}/Makefile.am

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
