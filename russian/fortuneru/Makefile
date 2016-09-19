# Created by: bestia@iptcom.net
# $FreeBSD$

PORTNAME=	fortuneru
PORTVERSION=	20090524
PORTREVISION=	1
CATEGORIES=	russian
MASTER_SITES=	ftp://bestia.kiev.ua/pub/files/ ftp://hosting.cvu.kiev.ua/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	obezpalko@gmail.com
COMMENT=	Fortunes in Russian

BROKEN=		unfetchable

PKGMESSAGE=	${WRKDIR}/pkg-message

.if exists(/usr/games/strfile)
STRCMD=		/usr/games/strfile
.elif exists(/usr/bin/strfile)
STRCMD=		/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

do-build:
	@for fortune in ${WRKSRC}/* ; do \
		${STRCMD} $$fortune ; \
	done

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/games/fortune/rus

.include <bsd.port.mk>
