# ports collection makefile for: 		trans-proxy-tor
# Date created: 				2006-06-11
# Whom:						Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	trans-proxy-tor
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://p56soo2ibjkx23xo.onion/ \
		http://www.fabiankeil.de/sourcecode/freebsd/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Transparent proxy used to redirect TCP connections into Tor

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Event/Lib.pm:${PORTSDIR}/devel/p5-Event-Lib

USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message

NO_BUILD=	yes

DEPRECATED=	trans-proxy-tor is rendered obsolete by Tor\'s TransPort option \
		(currently only available in tor-devel)

OPTIONS=	DNS_PROXY_TOR	"Depend on dns-proxy-tor"	On

HAVE_TOR!=	if pkg_info -I tor-\* >/dev/null 2>&1 ; then ${ECHO} YES; fi
.if ${HAVE_TOR} == "YES"
HAVE_TOR_DEVEL!=	if pkg_info -I tor-devel\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if ${HAVE_TOR_DEVEL} == "YES"
OPTIONS+=	TOR_DEVEL	"Depend on tor-devel (already installed)"	Off
.else
OPTIONS+=	TOR		"Depend on tor (already installed)"	Off
.endif

.else

OPTIONS+=	TOR_DEVEL	"Depend on tor-devel"	Off
OPTIONS+=	TOR		"Depend on tor"	Off

.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DNS_PROXY_TOR)
RUN_DEPENDS+=	${LOCALBASE}/bin/dns-proxy-tor:${PORTSDIR}/security/dns-proxy-tor
.endif

.if defined(WITH_TOR_DEVEL)
.if defined(WITH_TOR)
IGNORE=	cannot depend on tor and tor-devel at the same time
.endif

RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
.elif defined(WITH_TOR)
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
.endif

.if defined(NO_PF)
IGNORE=		requires PF
.endif

.if (${OSVERSION} < 502106)
IGNORE=		requires PF which is not available on FreeBSD versions below 5.3
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
do-install:
	${INSTALL} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in LICENSE README changelog filter-examples
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${CHOWN} -R _trans-proxy-tor:_trans-proxy-tor ${DOCSDIR}

.endif

post-install:
	${MKDIR} ${PREFIX}/var/run/${PORTNAME}
	${CHOWN} _trans-proxy-tor:_trans-proxy-tor ${PREFIX}/var/run/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
