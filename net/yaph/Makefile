# Created by: Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	yaph
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yaph is a proxy scanner

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaph/yaph ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yaph/yaph.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
