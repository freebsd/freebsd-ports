PORTNAME=	rotorouter
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	# nada
DISTFILES=	# nil

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Traceroute attempt logger and result spoofer

NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	rotorouter

do-extract:
	${MKDIR} ${WRKSRC}/src
	${CP} ${FILESDIR}/rotorouter.c ${WRKSRC}/src

do-build:
	${CC} ${CFLAGS} -lpcap -o ${WRKSRC}/src/rotorouter ${WRKSRC}/src/rotorouter.c

do-install:
	${INSTALL_DATA} ${FILESDIR}/rotorouter.conf-example \
		${STAGEDIR}${PREFIX}/etc/rotorouter.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/src/rotorouter ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
