# New ports collection makefile for:  firewalk
# Date created:		Sun May 3, 1999
# Whom:			shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	firewalk
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Yonatan@xpert.com
COMMENT=	A remote firewall auditing tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet	\
		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/Firewalk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN8=		firewalk.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/firewalk ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${MANPREFIX}/man/man8/
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/BUGS ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.	endif

.include <bsd.port.mk>
