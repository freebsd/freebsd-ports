# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	1.4.1
CATEGORIES=	www
MASTER_SITES=	http://web.onda.com.br/orso/

MAINTAINER=	mt@primats.org.ua
COMMENT=	Squid log analyzer and HTML report generator

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --enable-bindir="${PREFIX}/bin" --enable-sysconfdir="${PREFIX}/etc/${PORTNAME}" --with-gcc

MAN1=		sarg.1

post-extract:
	@${CHMOD} +x ${WRKSRC}/cfgaux ${WRKSRC}/include ${WRKSRC}/languages

.include <bsd.port.mk>
