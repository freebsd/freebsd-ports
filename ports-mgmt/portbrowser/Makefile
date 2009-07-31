# New ports collection makefile for:	portbrowser
# Date created:		8 November, 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	portbrowser
PORTVERSION=	0.5.20050618
PORTREVISION=	3
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	pb-browser-current-20050618
#MASTER_SITES=	http://www.bytelabs.org/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Graphical frontend for the BSD ports system

USE_GNOME=	gtk20
MAKE_ENV=	MANDIR=${PREFIX}/man/man \
		BINDIR=${PREFIX}/bin \
		NOMANCOMPRESS=YES
CFLAGS+= 	-DINDEXFILE=\\\"${PORTSDIR}/${INDEXFILE}\\\" \
		-DPORTS_DIR=\\\"${PORTSDIR}\\\"
PLIST_FILES=	bin/pbrowser

MAN1=		pbrowser.1

post-patch:
	@${REINPLACE_CMD} 's|gram-obsd.y|gram-fbsd.y|' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
