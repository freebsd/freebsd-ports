# Created by: ijliao
# $FreeBSD$

PORTNAME=	echolot
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF \
		http://benjamin-schweizer.de/files/echolot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer that grabs ARP packets on any ethernet devices

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		echolot.1
PORTDOCS=	*
PLIST_FILES=	bin/echolot

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
