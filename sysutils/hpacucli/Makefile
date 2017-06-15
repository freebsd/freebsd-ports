# Created by: SriSaiGanesh
# $FreeBSD$

PORTNAME=	hpacucli
PORTVERSION=	7.50
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/brooks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HP configuration utility for Smart Array RAID cards

RUN_DEPENDS=	compat4x-i386>0:misc/compat4x \
		compat5x-${ARCH}>0:misc/compat5x

USES=		tar:bzip2
NO_BUILD=	yes
IA32_BINARY_PORT=	yes

APP_PREFIX=	${PREFIX}/lib/compaq/hpacucli

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${APP_PREFIX}
	${INSTALL_LIB} ${WRKSRC}/lib*.so ${STAGEDIR}${APP_PREFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/.${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_LDCONFIG32=	${APP_PREFIX}
.else
USE_LDCONFIG=	${APP_PREFIX}
.endif

.include <bsd.port.post.mk>
