# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fex
PORTVERSION=	2.0.0
CATEGORIES=	textproc
MASTER_SITES=	http://semicomplete.googlecode.com/files/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Powerful field extraction tool

LICENSE=	APACHE20

BROKEN=		Unfetchable (google code has gone away)

MAKE_ENV+=	INSTALLMAN=${PREFIX}/man

PLIST_FILES=	bin/fex man/man1/fex.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
