# New ports collection makefile for:	fex
# Date created:				17 October 2011
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fex
PORTVERSION=	1.20111017.1
CATEGORIES=	sysutils
MASTER_SITES=	http://semicomplete.com/files/${PORTNAME}/ \
		http://people.rit.edu/rpsfa/distfiles/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A powerful field extraction tool

LICENSE=	ASL

PLIST_FILES=	bin/fex

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
