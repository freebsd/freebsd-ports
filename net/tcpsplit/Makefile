# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	tcpsplit
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://www.icir.org/mallman/software/tcpsplit/

MAINTAINER=	lars@eggert.org
COMMENT=	Breaks a libpcap trace along TCP connection boundaries

LICENSE=	MIT

PLIST_FILES=	bin/tcpsplit
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS|INC|LD)/d' ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpsplit ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
