# Created by: Loic Pefferkorn <loic-freebsd@loicp.eu>

PORTNAME=	burp
PORTVERSION=	2.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/grke/burp/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Network backup and restore program

LICENSE=	AGPLv3 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash \
		${LOCALBASE}/include/yajl/yajl_common.h:devel/yajl
LIB_DEPENDS=	librsync.so:net/librsync
RUN_DEPENDS=	bash:shells/bash

#USES=		gmake libtool ncurses pkgconfig ssl tar:bz2
USES=		libtool ncurses pkgconfig ssl tar:bz2

CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-all
USE_RC_SUBR=	burp

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	burp-devel

PORTSCOUT=	limit:^2\.2\.

OPTIONS_DEFINE=	IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

post-install:
.for file in CA.cnf burp.conf burp-server.conf clientconfdir/testclient
	${MV} ${STAGEDIR}${ETCDIR}/${file} ${STAGEDIR}${ETCDIR}/${file}.sample
.endfor

.include <bsd.port.mk>
