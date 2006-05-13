# ex:ts=8
# Ports collection makefile for:	hafiye
# Date Created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hafiye
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.enderunix.org/hafiye/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi Platform Customizable TCP/IP Packet Sniffer

MAKE_ENV=	LDFLAGS="-lpcap"

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g ; s|^CFLAGS|#CFLAGS|g ; \
		s|^LDFLAGS|#LDFLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hafiye ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/KB/* ${DATADIR}

.include <bsd.port.mk>
