# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cups
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common UNIX Printing System: Metaport to install complete system

RUN_DEPENDS=	espgs:${PORTSDIR}/${PKGCATEGORY}/cups-pstoraster \
		lpr-cups:${PORTSDIR}/${PKGCATEGORY}/cups-base \
		ttfread:${PORTSDIR}/${PKGCATEGORY}/cups-filters

USES=		metaport

SUB_FILES=	pkg-message

.include <bsd.port.mk>
