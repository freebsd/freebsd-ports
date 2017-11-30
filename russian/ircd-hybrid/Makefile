# Created by: Evgueni V. Gavrilov <aquatique@rusunix.org>
# $FreeBSD$

PORTNAME=	ircd
PORTVERSION=	7.2.4
PORTREVISION=	2
CATEGORIES=	russian irc
MASTER_SITES=	SF/${PORTNAME}-hybrid-ru/${PORTNAME}-hybrid-ru/${PORTNAME}-hybrid-ru-${PORTVERSION} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
PKGNAMESUFFIX=	-hybrid
DISTNAME=	ircd-hybrid-ru-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Russian version of well known hybrid IRC server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	ircd-[0-9]* irc-[0-9]* charybdis-[0-9]* Nefarious-[0-9]* ircd-hybrid-[0-9]* ircd-ratbox* bnc whois

BROKEN_aarch64=		fails to compile: passing void * to parameter of incompatible type
BROKEN_armv6=		fails to compile: passing void * to parameter of incompatible type
BROKEN_armv7=		fails to compile: passing void * to parameter of incompatible type

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-ru
USES=		bison ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd-hybrid-ru

USERS=		ircdru
GROUPS=		ircdru
PLIST_SUB=     USR=${USERS} GRP=${GROUPS}

.if defined(WITH_SMALL_NET)
CONFIGURE_ARGS+=-enable-small-net
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=--enable-syslog=\"kill squit connect users oper\"
.endif

.if defined(NICKLENGTH)
CONFIGURE_ARGS+=--with-nicklen=${NICKLENGTH}
.endif

.if defined(TOPICLENGTH)
CONFIGURE_ARGS+=--with-topiclen=${TOPICLENGTH}
.endif

.if defined(MAXCONN)
CONFIGURE_ARGS+=--with-maxconn=${MAXCONN}
.endif

pre-extract:
	@${ECHO_MSG} "* * * Build options for ircd-hybrid-ru * * *"
	@${ECHO_MSG} "Issue make WITH_SMALL_NET=yes to build server optimized for small network"
	@${ECHO_MSG} "Issue make WITH_SYSLOG=yes to enable logging via syslogd"
	@${ECHO_MSG} "You can define maximum nick length. For example make NICKLENGTH=46 (default is 30)"
	@${ECHO_MSG} "You can define maximum topic length. For example make TOPICLENGTH=254 (default is 120; maximum is 390)"
	@${ECHO_MSG} "You can define maximum number of connections for ircd. For example make MAXCONN=512"

post-extract:
	@${CP} ${WRKSRC}/contrib/m_ojoin.c ${WRKSRC}/modules/
	@${CP} ${WRKSRC}/contrib/m_force.c ${WRKSRC}/modules/

post-patch:
	@${REINPLACE_CMD} -e 's,-g -O2,-O2,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,"-g","",' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,ac_cv_prog_cc_g=yes,ac_cv_prog_cc_g=no,' ${WRKSRC}/configure

pre-install:
	@${REINPLACE_CMD} -e 's,ircd/etc/codepage,etc/ircd-hybrid-ru/codepage,' ${WRKSRC}/etc/example.conf
	@${REINPLACE_CMD} -e 's,/ircd/modules,/lib/ircd-hybrid-ru-modules,' ${WRKSRC}/etc/example.conf

post-install:
	${INSTALL_SCRIPT} -m 555 ${FILESDIR}/ircd-hybrid-ru.sh.sample ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELNOTE* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/server-version-info ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
