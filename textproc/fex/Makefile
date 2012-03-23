# New ports collection makefile for:	fex
# Date created:				17 October 2011
# Whom:					Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fex
PORTVERSION=	2.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://semicomplete.googlecode.com/files/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A powerful field extraction tool

LICENSE=	AL2

MAKE_ENV+=	INSTALLMAN=${PREFIX}/man

PLIST_FILES=	bin/fex
MAN1=		fex.1

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
