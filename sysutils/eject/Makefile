# New ports collection makefile for:	eject
# Date created:		03 January 2000
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	eject
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/OD/

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Utility for ejecting media from CD or optical disk drive

PLIST_FILES=	sbin/eject
PORTDOCS=	README README-J

MAN1=		eject.1
MANCOMPRESSED=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
