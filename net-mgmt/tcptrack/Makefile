# New ports collection makefile for:	tcptrack
# Date created:		2004-10-11
# Whom:			Tor Halvard "Squat" Furulund <squat@squat.no>
#
# $FreeBSD$
#

PORTNAME=		tcptrack
PORTVERSION=		1.1.5
CATEGORIES=		net-mgmt
MASTER_SITES=		http://www.rhythm.cx/~steve/devel/tcptrack/
MASTER_SITE_SUBDIR=	release/${PORTVERSION}/source/

MAINTAINER=	squat@squat.no
COMMENT=	Packet sniffer which displays TCP information like top(1)

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/tcptrack
MAN1=		tcptrack.1
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
