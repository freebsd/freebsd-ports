# Created by: Loic Pefferkorn <loic-freebsd@loicp.eu>
# $FreeBSD$

PORTNAME=	burp
PORTVERSION?=	2.2.18
# whenever PORTREVISION is increased,
# sysutils/burp-devel's PKGVERSION must also increase
PORTREVISION?=	3
CATEGORIES=	sysutils

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Network backup and restore program

LICENSE=	AGPLv3 PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash \
		${LOCALBASE}/include/yajl/yajl_common.h:devel/yajl
LIB_DEPENDS=	librsync.so:net/librsync2
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool ncurses pkgconfig ssl
USE_RC_SUBR=	burp
USE_GITHUB=	yes
GH_ACCOUNT=	grke

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

INSTALL_TARGET=	install-all

CONFLICTS_INSTALL?=	burp-devel
PORTSCOUT?=		limit:^2\.2\.

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

CONFIG_FILES=	CA.cnf \
		burp-server.conf \
		burp.conf \
		clientconfdir/testclient

post-install:
.for FILE in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${ETCDIR}/${FILE} \
		${STAGEDIR}${ETCDIR}/${FILE}.sample
.endfor

.include <bsd.port.mk>
