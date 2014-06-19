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

OPTIONS_DEFINE=	SUID
SUID_DESC=	Install with the sticky bit (mode 4110)

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUID}
BINMODE=	4110
.else
BINMODE=	0100
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
