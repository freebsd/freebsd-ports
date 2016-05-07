# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	firewalk
PORTVERSION=	5.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	Remote firewall auditing tool

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libnet.so:net/libnet

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/firewalk man/man8/firewalk.8.gz
PORTDOCS=	BUGS README TODO

WRKSRC=		${WRKDIR}/Firewalk

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/firewalk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
