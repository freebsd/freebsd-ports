# ex:ts=8
# Ports collection makefile for:	anubis
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#
###########################################################################
#
# Following compile-time options are available:
#
# WITH_GNUTLS=yes	Enable GnuTLS API instead of default OpenSSL API
# WITHOUT_OPENSSL=yes	Disable the OpenSSL support; unless WITH_GNUTLS
#			is specified, this will disables TLS/SSL suport
# WITHOUT_GPGME=yes	Disable the GnuPG (GPGME library) support
# WITH_PCRE=yes		Enable the PCRE library support
#
###########################################################################

PORTNAME=	anubis
PORTVERSION=	3.6.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt" \
		MAKEINFO="makeinfo --no-split"

# Select TLS/SSL API: either OpenSSL (default), GnuTLS, or none
.if defined(WITH_GNUTLS)
USE_GNUTLS=		yes
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.elif !defined(WITHOUT_OPENSSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

# GPGME
.if defined(WITHOUT_GPGME)
CONFIGURE_ARGS+=	--without-gpgme
.else
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme
.endif

# PCRE
.if defined(WITH_PCRE)
LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.endif

# PAM
.if exists(/usr/lib/libpam.so)
USE_PAM=		yes
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		PAM=""
.else
PLIST_SUB+=		PAM="@comment "
.endif

# TCP Wrappers
.if exists(/usr/include/tcpd.h)
USE_TCP_WRAPPERS=	yes
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

MAN1=	anubis.1
DOCS=	AUTHORS INSTALL NEWS README THANKS TODO

pre-configure:
	@${ECHO_MSG} ""
.if defined(USE_OPENSSL)
	@${ECHO_MSG} "Using OpenSSL as TLS/SSL API"
.elif defined(USE_GNUTLS)
	@${ECHO_MSG} "Using GnuTLS as TLS/SSL API"
.else
	@${ECHO_MSG} "Disabling TLS/SSL support"
.endif
.if defined(WITHOUT_GPGME)
	@${ECHO_MSG} "Disabling GnuPG (GPGME) support"
.endif
.if defined(WITH_PCRE)
	@${ECHO_MSG} "Enabling PCRE support"
.else
	@${ECHO_MSG} "You could define WITH_PCRE to enable PCRE support"
.endif
.if defined(USE_PAM)
	@${ECHO_MSG} "Enabling PAM support"
.endif
.if defined(USE_TCP_WRAPPERS)
	@${ECHO_MSG} "Enabling TCP wrappers support"
.endif
	@${ECHO_MSG} ""
	@${RM} -f ${WRKSRC}/doc/anubis.info*

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/anubis.sh > \
		${WRKSRC}/anubis.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/anubis.sh ${PREFIX}/etc/rc.d/anubis.sh.sample
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*rc ${EXAMPLESDIR}
.if defined(USE_PAM)
	@${MKDIR} ${EXAMPLESDIR}/pam
	${INSTALL_DATA} ${WRKSRC}/examples/pam/* ${EXAMPLESDIR}/pam
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
