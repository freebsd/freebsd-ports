# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mt@primats.org.ua
COMMENT=	Squid log analyzer and HTML report generator

.if !defined(WITHOUT_GD)
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CC=gcc --enable-bindir="${PREFIX}/bin" --enable-sysconfdir="${PREFIX}/etc/${PORTNAME}" --enable-htmldir=${PREFIX}/www/${PORTNAME}

.if !defined(WITHOUT_GD)
CFLAGS+=	-I ${LOCALBASE}/include -L ${LOCALBASE}/lib
.endif

MAN1=		sarg.1

post-extract:
	@${CHMOD} +x ${WRKSRC}/sarg-php/locale

post-configure:
.if !defined(WITHOUT_GD)
	@${SED} -i .orig 's|^\(LDFLAGS.*\)|\1 -I ${LOCALBASE}/include -L ${LOCALBASE}/lib|g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
