# Created by: Jesse Smith <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	cpulimit
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/limitcpu/limitcpu/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A program to limit the CPU usage of a process

LICENSE=	GPLv2

CFLAGS+=	-lkvm -Wall -O2
MANCOMPRESSED=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|share/||g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
