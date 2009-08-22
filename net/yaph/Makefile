# New ports collection makefile for:	yaph
# Date created:		14 jui 2003
# Whom:			Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	yaph
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Yaph is a proxy scanner

GNU_CONFIGURE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/yaph/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaph/yaph ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yaph/yaph.conf ${PREFIX}/etc

.include <bsd.port.mk>
