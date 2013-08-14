# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	onioncat
PORTVERSION=	0.2.2.r554
CATEGORIES=	net security
MASTER_SITES=	https://www.cypherpunk.at/ocat/download/Source/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP-transparent Tor Hidden Service connector

LICENSE=	GPLv3

RUN_DEPENDS=	tor:${PORTSDIR}/security/tor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-pthread"

USE_RC_SUBR=	${PORTNAME}
MAN1=		ocat.1
PLIST_FILES=	bin/ocat

post-patch:
	@${REINPLACE_CMD} -e \
		'/CFLAGS=/s|-O2|$$CFLAGS|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ocat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/ocat.1 ${MANPREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
