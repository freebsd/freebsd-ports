# Created by: SriSaiGanesh
# $FreeBSD$

PORTNAME=	hpacucli
PORTVERSION=	7.50
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/brooks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HP configuration utility for Smart Array RAID cards

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x \
		c.5:${PORTSDIR}/misc/compat5x

USE_BZIP2=	yes
NO_BUILD=	yes
IA32_BINARY_PORT=	yes

APP_PREFIX=	${PREFIX}/lib/compaq/hpacucli

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${APP_PREFIX}
	${CP} -a ${WRKSRC}/lib* ${APP_PREFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/.${PORTNAME} ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_LDCONFIG32=	${APP_PREFIX}
.  if ${OSVERSION} < 1000019
BROKEN=		currently does not work on amd64 (see PR ports/128288)
.  endif
.else
USE_LDCONFIG=	${APP_PREFIX}
.endif

.include <bsd.port.post.mk>
