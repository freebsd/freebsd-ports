# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autosig
PORTVERSION=	2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.irendi.com/~msharpe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Random .signature generator with header file included

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

MAKEFILE=	makefile
PLIST_FILES=	bin/autosig
ALL_TARGET=	${PORTNAME}

pre-build:
	${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
