# Ports collection makefile for:	anubis
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	anubis
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Outgoing SMTP mail processor

USE_RC_SUBR=	anubis
USE_AUTOTOOLS=	aclocal autoheader autoconf automake
ACLOCAL_ARGS=	-I m4 -I am
AUTOMAKE_ARGS=	--force

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		anubis.1
INFO=		anubis
PORTEXAMPLES=	1anubisrc 2anubisrc

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	NLS "Native language support" on \
		GUILE "Guile support" on \
		GPGME "GPG support via gpgme" on \
		GNUTLS "GNU TLS support" on \
		GSASL "GSASL support (required for databases)" on \
		GDBM "GDBM database support" off \
		MYSQL "MySQL database support" off \
		PGSQL "PostgreSQL database support" off \
		PCRE "Perl-style regular expressions" off \
		PAM "PAM support" off \
		SOCKS "SOCKS proxy support" off \
		TCPWRAP "TCP wrappers" off

.include <bsd.port.options.mk>

# Default requirement for anubis rc script
_REQUIRE=	mail

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_ICONV=	yes
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_GUILE)
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	GUILE="@comment "
.else
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
PORTEXAMPLES+=	anubis.scm anubisrc.guile
PLIST_SUB+=	GUILE=""
.endif

.if defined(WITHOUT_GPGME)
CONFIGURE_ARGS+=--without-gpgme
.else
LIB_DEPENDS+=	gpgme.18:${PORTSDIR}/security/gpgme
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=--without-gnutls
.else
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.endif

.if defined(WITH_GDBM)
.undef WITHOUT_GSASL
WITH_GSASL=	yes
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-gdbm
.endif

.if defined(WITH_MYSQL)
.undef WITHOUT_GSASL
WITH_GSASL=	yes
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
_REQUIRE+=	mysql
.endif

.if defined(WITH_PGSQL)
.undef WITHOUT_GSASL
WITH_GSASL=	yes
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
_REQUIRE+=	postgresql
.endif

.if defined(WITHOUT_GSASL)
CONFIGURE_ARGS+=--without-gsasl
PLIST_SUB+=	GSASL="@comment "
.else
LIB_DEPENDS+=	gsasl.15:${PORTSDIR}/security/gsasl
PLIST_SUB+=	GSASL=""
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre
.endif

.if defined(WITH_PAM) && exists(/usr/lib/libpam.so)
CONFIGURE_ARGS+=--with-pam
PORTEXAMPLES+=	pam
.endif

.if defined(WITH_TCPWRAP) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=--with-tcp-wrappers
.endif

.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=--with-socks-proxy
.endif

SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*rc ${EXAMPLESDIR}
.if defined(WITH_GUILE)
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} anubis.scm anubisrc.guile ${EXAMPLESDIR}
.endif
.if defined(WITH_PAM)
	@${MKDIR} ${EXAMPLESDIR}/pam
	${INSTALL_DATA} ${WRKSRC}/examples/pam/anubis* ${EXAMPLESDIR}/pam
.endif
.endif

.include <bsd.port.mk>
