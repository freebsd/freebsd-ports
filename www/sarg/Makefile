# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mt@primats.org.ua
COMMENT=	Squid log analyzer and HTML report generator

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CC=gcc --enable-bindir="${PREFIX}/bin" --enable-sysconfdir="${PREFIX}/etc/${PORTNAME}" --enable-htmldir=${PREFIX}/www/${PORTNAME}

MAN1=		sarg.1

post-extract:
	@${CHMOD} +x ${WRKSRC}/sarg-php/locale

.include <bsd.port.mk>
