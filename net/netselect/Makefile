# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	netselect
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://apenwarr.ca/netselect/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultrafast implementation of ping

LICENSE=	BSD3CLAUSE

BROKEN=		Does not work (sendto: Invalid argument)

OPTIONS_DEFINE=	SUID
OPTIONS_SUB=	yes
SUID_DESC=	Install with the setuid bit (mode 4110)

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
