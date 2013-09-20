# Created by: Paul Chvostek <paul@it.ca>
# $FreeBSD$

PORTNAME=	rotorouter
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	# nada
DISTFILES=	# nil

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Traceroute attempt logger and result spoofer

NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	rotorouter

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKSRC}/src
	${CP} ${FILESDIR}/rotorouter.c ${WRKSRC}/src

do-build:
		${CC} -lpcap -o ${WRKSRC}/src/rotorouter ${WRKSRC}/src/rotorouter.c

do-install:
		@${INSTALL_DATA} -m 640 ${FILESDIR}/rotorouter.conf-example ${PREFIX}/etc
		@${INSTALL_DATA} -m 640 ${FILESDIR}/rotorouter.conf-example ${PREFIX}/etc/rotorouter.conf
		@${INSTALL_PROGRAM} ${WRKSRC}/src/rotorouter ${PREFIX}/sbin

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
