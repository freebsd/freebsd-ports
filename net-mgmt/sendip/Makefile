# Created by: joseph@randomnetworks.com
# $FreeBSD$

PORTNAME=	sendip
PORTVERSION=	2.5
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.earth.li/projectpurple/files/

MAINTAINER=	coco@executive-computing.de
COMMENT=	Command-line tool for sending arbitrary IP packets

LICENSE=	GPLv2

BUILD_DEPENDS=	help2man:misc/help2man

USES=		gmake perl5 compiler

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-empty-body -Wno-constant-conversion
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sendip
.for slib in ipv4.so ipv6.so icmp.so tcp.so udp.so rip.so ripng.so ntp.so \
bgp.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sendip/${slib}
.endfor

.include <bsd.port.post.mk>
