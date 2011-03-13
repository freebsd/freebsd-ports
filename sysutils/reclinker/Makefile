# New ports collection makefile for:	reclinker
# Date created:		11 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reclinker
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://creo.hu/~csaba/stuff/reclinker/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recursive symlinking utility

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/${PORTNAME} bin/recdeleter bin/reclinktester
MAKEFILE=	Makefile.m4
ALL_TARGET=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/^PREFIX=/d;/^CC=/d;/^CFLAGS=/d;/^ifelse/,/^)/d;\
		s|cp -a|${INSTALL_PROGRAM}|' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
