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

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet \
		libnet.so:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include `${LIBNET_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

PLIST_FILES=	bin/firewalk man/man8/firewalk.8.gz
PORTDOCS=	BUGS README TODO

WRKSRC=		${WRKDIR}/Firewalk

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/firewalk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
