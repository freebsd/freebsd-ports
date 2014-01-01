# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fex
PORTVERSION=	2.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://semicomplete.googlecode.com/files/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A powerful field extraction tool

LICENSE=	APACHE20

MAKE_ENV+=	INSTALLMAN=${PREFIX}/man

PLIST_FILES=	bin/fex
MAN1=		fex.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
