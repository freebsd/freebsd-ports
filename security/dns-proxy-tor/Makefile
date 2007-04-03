# ports collection makefile for: 		dns-proxy-tor
# Date created: 				2006-06-11
# Whom:						Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	dns-proxy-tor
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	security dns
MASTER_SITES=	http://p56soo2ibjkx23xo.onion/ \
		http://www.fabiankeil.de/sourcecode/freebsd/
DISTNAME=	trans-proxy-tor-${PORTVERSION}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Resolves DNS requests through Tor

USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	pkg-message

HAVE_TOR!=	if pkg_info -I tor-\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR} == "YES")
HAVE_TOR_DEVEL!=	if pkg_info -I tor-devel\* >/dev/null 2>&1 ; then ${ECHO} YES; fi

.if (${HAVE_TOR_DEVEL} == "YES")
OPTIONS=	TOR_DEVEL	"Depend on tor-devel (already installed)"	On
.else
OPTIONS=	TOR		"Depend on tor (already installed)"	On
.endif

.else

OPTIONS= 	TOR_DEVEL	"Depend on tor-devel"	On \
		TOR		"Depend on tor"		Off

.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TOR_DEVEL)
.if defined(WITH_TOR)
IGNORE=		cannot depend on tor and tor-devel at the same time
.endif
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
.elif defined(WITH_TOR)
RUN_DEPENDS+=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor
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
	${CHOWN} -R _dns-proxy-tor:_dns-proxy-tor ${DOCSDIR}

.endif

post-install:
	${MKDIR} ${PREFIX}/var/run/${PORTNAME}
	${CHOWN} _dns-proxy-tor:_dns-proxy-tor ${PREFIX}/var/run/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
