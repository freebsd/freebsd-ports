# Created by: kaz
# $FreeBSD$

PORTNAME=	vrfy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://jadawin.tuxaco.net/freebsd/
DISTNAME=	${PORTNAME}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Verify mail address

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" RES=""
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/vrfy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vrfy ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
