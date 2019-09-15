# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	wackford-squeers
PORTVERSION=	1.19
CATEGORIES=	net
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plain text network hypertext server and client

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

RUN_DEPENDS=	${LOCALBASE}/bin/munger:lang/munger

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

.include <bsd.port.mk>
