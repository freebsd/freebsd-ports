# ex:ts=8
# Ports collection makefile for:	gspoof
# Date created:			Jan 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gspoof
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console/GTK+ TCP/IP Packets Forger

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GETOPT_LONG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}"
ALL_TARGET=	gtk

post-patch:
	@${REINPLACE_CMD} -e "s|gtk-config|\$${GTK_CONFIG}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
