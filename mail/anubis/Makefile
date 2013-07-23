# Ports collection makefile for:	anubis
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	anubis
PORTVERSION=	4.1.1
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Outgoing SMTP mail processor

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS EXAMPLES GUILE GPGME GNUTLS GSASL \
		GDBM MYSQL PGSQL PCRE PAM SOCKS LIBWRAP
OPTIONS_DEFAULT=GUILE GPGME GNUTLS GSASL
NO_OPTIONS_SORT=yes

GPGME_DESC=	GnuPG support via GPGME
GSASL_DESC=	GSASL support (required for databases)
GDBM_DESC=	GDBM backend
SOCKS_DESC=	SOCKS proxy support

USE_RC_SUBR=	anubis
USE_AUTOTOOLS=	aclocal autoheader autoconf automake
ACLOCAL_ARGS=	-I m4 -I am
AUTOMAKE_ARGS=	--force --add-missing

MAN1=		anubis.1
INFO=		anubis
PORTEXAMPLES=	1anubisrc 2anubisrc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

# Default requirement for anubis rc script
_REQUIRE=	mail

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
PORTEXAMPLES+=	anubis.scm anubisrc.guile
PLIST_SUB+=	GUILE=""
.else
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	GUILE="@comment "
.endif

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=	gpgme:${PORTSDIR}/security/gpgme
.else
CONFIGURE_ARGS+=--without-gpgme
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=--without-gnutls
.endif

.if ${PORT_OPTIONS:MGSASL} || ${PORT_OPTIONS:MGDBM} || ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
LIB_DEPENDS+=	gsasl:${PORTSDIR}/security/gsasl
PLIST_SUB+=	GSASL=""
.else
CONFIGURE_ARGS+=--without-gsasl
PLIST_SUB+=	GSASL="@comment "
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-gdbm
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
_REQUIRE+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
_REQUIRE+=	postgresql
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre
.endif

.if ${PORT_OPTIONS:MPAM} && exists(/usr/lib/libpam.so)
CONFIGURE_ARGS+=--with-pam
PORTEXAMPLES+=	pam
.endif

.if ${PORT_OPTIONS:MLIBWRAP} && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=--with-tcp-wrappers
.endif

.if ${PORT_OPTIONS:MSOCKS}
CONFIGURE_ARGS+=--with-socks-proxy
.endif

SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*rc ${EXAMPLESDIR}
.   if ${PORT_OPTIONS:MGUILE}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} anubis.scm anubisrc.guile ${EXAMPLESDIR}
.   endif
.   if ${PORT_OPTIONS:MPAM}
	@${MKDIR} ${EXAMPLESDIR}/pam
	${INSTALL_DATA} ${WRKSRC}/examples/pam/anubis* ${EXAMPLESDIR}/pam
.   endif
.endif

.include <bsd.port.mk>
