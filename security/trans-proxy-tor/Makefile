# ports collection makefile for: 		trans-proxy-tor
# Date created: 				2006-06-11
# Whom:						Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	trans-proxy-tor
PORTVERSION=	0.1.0
CATEGORIES=	security net
MASTER_SITES=	http://p56soo2ibjkx23xo.onion/ \
		http://www.fabiankeil.de/sourcecode/freebsd/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Transparent proxy used to redirect TCP connections into Tor

RUN_DEPENDS=	${LOCALBASE}/bin/dns-proxy-tor:${PORTSDIR}/security/dns-proxy-tor \
		${SITE_PERL}/${PERL_ARCH}/Event/Lib.pm:${PORTSDIR}/devel/p5-Event-Lib \
		${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel

USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(NO_PF)
IGNORE=		requires PF
.endif

.if (${OSVERSION} < 502106)
IGNORE=		requires PF which is not available on FreeBSD versions below 5.3
.endif

do-build:
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
