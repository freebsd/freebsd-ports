# Created by: Xiaoding Liu <xiaoding+freebsd@xiaoding.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
DISTVERSIONPREFIX=v
PORTVERSION=	1.6.4
CATEGORIES=	net

MAINTAINER=	xiaoding+freebsd@xiaoding.org
COMMENT=	Lightweight tunnel proxy which can help you get through firewalls

LICENSE=	GPLv3

# fetch from github repo
USE_GITHUB=	yes
GH_ACCOUNT=	madeye

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla

USE_RC_SUBR=	shadowsocks_libev

post-patch:
	${REINPLACE_CMD} -e 's|^pkgconfiglibdir.*|pkgconfiglibdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${WRKSRC}/debian/config.json  ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
