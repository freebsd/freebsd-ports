# New ports collection makefile for:	eject
# Date created:		03 January 2000
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	eject
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/OD/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/OD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for ejecting media from CD or optical disk drive

DOCDIR=		share/doc/eject
PLIST_SUB=	DOCDIR=${DOCDIR}

MAN1=		eject.1
MANCOMPRESSED=	yes

post-install:
	@if [ ! -d ${PREFIX}/${DOCDIR} ] ; then \
		${MKDIR} ${PREFIX}/${DOCDIR} ; \
	fi
	@for i in README README-J ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR} ; \
	done

.include <bsd.port.mk>
