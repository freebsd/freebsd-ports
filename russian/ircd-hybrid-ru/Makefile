# New ports collection makefile for:	ircd-hybrid-ru
# Date Created:				2003.12.14
# Whom:					Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	ircd
PORTVERSION=	7.2.2
CATEGORIES=	irc russian
MASTER_SITES=	SF/${PORTNAME}-hybrid-ru/${PORTNAME}-hybrid-ru/${PORTNAME}-hybrid-ru-${PORTVERSION} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/

PKGNAMESUFFIX=	-hybrid-ru
DISTNAME=	ircd-hybrid-ru-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Russian version of well known hybrid IRC server

CONFLICTS=	ircd-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}
USE_OPENSSL=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd-hybrid-ru

MAN8=		ircd.8

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
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${REINPLACE_CMD} -e 's,ircd/etc/codepage,etc/ircd-hybrid-ru/codepage,' ${WRKSRC}/etc/example.conf
	@${REINPLACE_CMD} -e 's,/ircd/modules,/lib/ircd-hybrid-ru-modules,' ${WRKSRC}/etc/example.conf

post-install:
	@${INSTALL_SCRIPT} -m 555 ${FILESDIR}/ircd-hybrid-ru.sh.sample ${PREFIX}/etc/rc.d
	@${CHOWN} -R ircdru:ircdru ${PREFIX}/etc/ircd-hybrid-ru
	@${CHOWN} -R ircdru:ircdru /var/log/ircd-hybrid-ru
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/RELNOTE* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/server-version-info ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
