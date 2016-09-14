# Created by: bestia@iptcom.net
# $FreeBSD$

PORTNAME=	fortuneru
PORTVERSION=	20090524
PORTREVISION=	1
CATEGORIES=	russian
MASTER_SITES=	ftp://bestia.kiev.ua/pub/files/ \
		ftp://hosting.cvu.kiev.ua/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	obezpalko@gmail.com
COMMENT=	Fortunes in Russian

BROKEN=		unfetchable

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRCMD=		${LOCALBASE}/bin/fortune_strfile
PKGMESSAGE=	${WRKDIR}/pkg-message

do-build:
	for fortune in ${WRKSRC}/* ; do \
		${STRCMD} $$fortune ; \
	done

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/* \
		${STAGEDIR}${PREFIX}/share/games/fortune/rus

.include <bsd.port.mk>
