# New ports collection Makefile for:   newscache
# Date created:                23 February 2002
# Whom:                        Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newscache
PORTVERSION=	1.2.r.6
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.linuxhacker.at/linux/downloads/src/
DISTNAME=	NewsCache-${PORTVERSION:S/.r./rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NewsCache is a free cache server for USENET News

LIB_DEPENDS=	socket[+][+].1:${PORTSDIR}/net/libsocket++

USE_AUTOMAKE_VER=	19
USE_AUTOHEADER_VER=	259
USE_AUTOCONF_VER=	259
USE_GETOPT_LONG=	yes
USE_REINPLACE=		yes
AUTOMAKE_ARGS=		--add-missing
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc

MAN5=	newscache.conf.5
MAN8=	newscache.8 newscacheclean.8 updatenews.8
INFO=	NewsCache

post-patch:
	${REINPLACE_CMD} -e "s,-pedantic,," ${WRKSRC}/configure.in

pre-configure:
	(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${SH} ./autogen)

.include <bsd.port.mk>
