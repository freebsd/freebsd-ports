# New ports collection makefile for:	onioncat
# Date created:		2010-05-09
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	onioncat
PORTVERSION=	0.2.2.r552
CATEGORIES=	net security
MASTER_SITES=	http://www.cypherpunk.at/ocat/download/Source/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IP-Transparent Tor Hidden Service Connector

RUN_DEPENDS=	tor:${PORTSDIR}/security/tor

GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}
MAN1=		ocat.1
PLIST_FILES=	bin/ocat

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ocat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/ocat.1 ${PREFIX}/man/man1/ocat.1

.include <bsd.port.post.mk>
