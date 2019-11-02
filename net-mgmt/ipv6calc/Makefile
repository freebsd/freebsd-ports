# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	ipv6calc
PORTVERSION=	2.2.0
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Convert, change, and calculate with IPv6 addresses

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5 shebangfix ssl

GNU_CONFIGURE=	yes

SHEBANG_FILES=	tools/*.pl tools/*.sh.in

.include <bsd.port.pre.mk>

.if !(${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64)
CFLAGS+=	-Wno-unknown-warning-option
.else
CFLAGS+=	-Wno-uninitialized
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.post.mk>
