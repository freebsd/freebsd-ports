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
# WITHOUT_OPENSSL=yes	Disable the OpenSSL library support
# WITHOUT_GPGME=yes	Disable the GnuPG (GPGME library) support
# WITH_PCRE=yes		Enable the PCRE library support
# WITH_PAM=yes		Enable the Pluggable Authentication Modules support
# WITH_TCP_WRAPPERS=yes Enable the libwrap (TCP wrappers) support
#
###########################################################################

PORTNAME=	anubis
PORTVERSION=	3.5.0
PORTCOMMENT=	Outgoing SMTP mail processor
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt" \
		MAKEINFO="makeinfo --no-split"

# OpenSSL
.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-openssl
.else
USE_OPENSSL=		yes
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
.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=	PAM=""
.else
PLIST_SUB+=	PAM="@comment "
.endif

# TCP Wrappers
.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

MAN1=	anubis.1
DOCS=	AUTHORS INSTALL NEWS README THANKS TODO

pre-fetch:
	@${ECHO_MSG} ""
.if defined(WITHOUT_OPENSSL)
	@${ECHO_MSG} "Building Anubis without OpenSSL support"
.else
	@${ECHO_MSG} "Building Anubis with OpenSSL support (default)"
	@${ECHO_MSG} "-- You could define WITHOUT_OPENSSL to disable OpenSSL support"
.endif
.if defined(WITHOUT_GPGME)
	@${ECHO_MSG} "Building Anubis without GnuPG (GPGME library) support"
.else
	@${ECHO_MSG} "Building Anubis with GnuPG (GPGME library) support (default)"
	@${ECHO_MSG} "-- You could define WITHOUT_GPGME to disable GPGME support"
.endif
.if defined(WITH_PCRE)
	@${ECHO_MSG} "Building Anubis with PCRE library support"
.else
	@${ECHO_MSG} "You could define WITH_PCRE to build Anubis with PCRE support"
.endif
.if defined(WITH_PAM)
	@${ECHO_MSG} "Building Anubis with PAM library support"
.else
	@${ECHO_MSG} "You could define WITH_PAM to build Anubis with PAM support"
.endif
.if defined(WITH_TCP_WRAPPERS)
	@${ECHO_MSG} "Building Anubis with TCP wrappers support"
.else
	@${ECHO_MSG} "You could define WITH_TCP_WRAPPERS to build Anubis with TCP wrappers support"
.endif
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/anubis.sh > \
		${WRKSRC}/anubis.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/anubis.info*

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/anubis.sh ${PREFIX}/etc/rc.d
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*rc ${EXAMPLESDIR}
.if defined(WITH_PAM)
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
