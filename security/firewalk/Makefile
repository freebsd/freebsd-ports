# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	firewalk
PORTVERSION=	5.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	Remote firewall auditing tool

LIB_DEPENDS=	dnet:${PORTSDIR}/net/libdnet \
		net:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/Firewalk

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `${LIBNET_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8=		firewalk.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

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
