# Created by: Russell A. Jackson <rjackson@cserv62.csub.edu>
# $FreeBSD$

PORTNAME=	sdig
PORTVERSION=	0.45
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Translate IP/DNS/WINS/MAC address into port description

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sdig etc/sdig.conf etc/mactable man/man5/sdig.conf.5.gz \
		man/man8/sdig.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdig ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sdig.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mactable ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/sdig.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/sdig.conf.5 ${STAGEDIR}${PREFIX}/man/man5

.include <bsd.port.mk>
