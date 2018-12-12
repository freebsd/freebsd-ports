# Created by: Loic Pefferkorn <loic-freebsd@loicp.eu>
# $FreeBSD$

PORTNAME=	burp
PORTVERSION=	1.4.40
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network backup and restore program

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	librsync.so:net/librsync2

OPTIONS_DEFINE=		IPV6

USE_GITHUB=	yes
GH_ACCOUNT=	grke

USE_RC_SUBR=	burp
GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake localbase ncurses ssl

PORTSCOUT=	limit:^1\.4\.

CONFIGURE_ARGS=	--sbindir="${PREFIX}/sbin" \
		--sysconfdir=${ETCDIR} \

IPV6_CONFIGURE_ENABLE=	ipv6

CONFIG_FILES=	configs/server/burp.conf \
		configs/client/burp.conf \
		configs/certs/CA/CA.cnf

post-patch:
.for f in ${CONFIG_FILES}
	@${REINPLACE_CMD} -e 's,/etc/burp,${PREFIX}/etc/burp,g' ${WRKSRC}/${f}
	@${REINPLACE_CMD} -e 's,/usr/sbin,${PREFIX}/sbin,g' ${WRKSRC}/${f}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/bedup
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vss_strip
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/burp

.include <bsd.port.mk>
