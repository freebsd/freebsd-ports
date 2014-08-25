# Created by: Tor Halvard "Squat" Furulund <squat@squat.no>
# $FreeBSD$

PORTNAME=		tcptrack
PORTVERSION=		1.3.0
CATEGORIES=		net-mgmt
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/%SUBDIR%/
MASTER_SITE_SUBDIR=	release/${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer which displays TCP information like top(1)

GNU_CONFIGURE=	yes

NO_STAGE=	yes
PLIST_FILES=	bin/tcptrack
MAN1=		tcptrack.1
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
