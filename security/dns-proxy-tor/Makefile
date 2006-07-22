# ports collection makefile for: 		dns-proxy-tor
# Date created: 				2006-06-11
# Whom:						Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	dns-proxy-tor
PORTVERSION=	0.1.0
CATEGORIES=	security dns
MASTER_SITES=	http://p56soo2ibjkx23xo.onion/ \
		http://www.fabiankeil.de/sourcecode/freebsd/
DISTNAME=	trans-proxy-tor-${PORTVERSION}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Resolves DNS requests through Tor

RUN_DEPENDS=	${LOCALBASE}/bin/tor:${PORTSDIR}/security/tor-devel
USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
SUB_FILES=	pkg-message

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
	${CHOWN} -R _dns-proxy-tor:_dns-proxy-tor ${DOCSDIR}

.endif

post-install:
	${MKDIR} ${PREFIX}/var/run/${PORTNAME}
	${CHOWN} _dns-proxy-tor:_dns-proxy-tor ${PREFIX}/var/run/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
