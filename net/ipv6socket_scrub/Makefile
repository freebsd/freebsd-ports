# New ports collection makefile for:    IPv6socket_scrub
# Date created:         22.03.2002
# Whom: Janos Mohacsi <janos.mohacsi@dante.org.uk>
#
# $FreeBSD$

PORTNAME=	ipv6socket_scrub
PORTVERSION=	1.0
CATEGORIES=	net devel ipv6
MASTER_SITES=	#http://www.sun.com/download/index.jsp?cat=Operating%20Systems&tab=3
DISTNAME=	IPv6socket_scrub
EXTRACT_SUFX=	.tar

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Checks IPv6 portability of C source code

MAN1=		ipv6socket_scrub.1
PLIST_FILES=	bin/ipv6socket_scrub

WRKSRC=			${WRKDIR}/${DISTNAME}/src
RESTRICTED=		"not redistributable, license agreement required"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	${ECHO} '======================================================='; \
	${ECHO} 'You need to sign the agreement on http://www.sun.com/download/index.jsp?cat=Operating%20Systems&tab=3'; \
	${ECHO} 'and fetch on your own.'; \
	${ECHO} 'Once ${DISTFILES} has been downloaded, move it to '; \
	${ECHO} '${DISTDIR} and then restart this build '; \
	${ECHO} '======================================================='; \
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipv6socket_scrub ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../Docs/man/man1/ipv6socket_scrub.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
