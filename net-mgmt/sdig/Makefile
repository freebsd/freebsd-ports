# New ports collection makefile for: sdig
# Date created: 25 May 2004
# Whom: Russell A. Jackson <rjackson@cserv62.csub.edu>
#
# $FreeBSD$
#

PORTNAME=	sdig
PORTVERSION=	0.45
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Translate IP/DNS/WINS/MAC address into port description

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN5=		sdig.conf.5
MAN8=		sdig.8
PLIST_FILES=	bin/sdig etc/sdig.conf etc/mactable

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdig ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sdig.conf ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mactable ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/sdig.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/sdig.conf.5 ${PREFIX}/man/man5

.include <bsd.port.mk>
