PORTNAME=	ipsvd
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://smarden.org/ipsvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet protocol service daemons
WWW=		http://smarden.org/ipsvd/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/package/COPYING

BROKEN_armv6=		fails to install: Checking udpsvd... drop: unable to read from socket: bad address
BROKEN_armv7=		fails to install: Checking udpsvd... drop: unable to read from socket: bad address
BROKEN_mips64=		fails to install: tcpsvd failed
BROKEN_riscv64=		fails to install: Checking udpsvd... drop: unable to read from socket: bad address

WRKSRC=		${WRKDIR}/net/${DISTNAME}
ALL_TARGET=	default

DEPRECATED=	bogus assumption of system type widths, likely crash-prone
EXPIRATION_DATE=2023-12-31

DOCS=		package/CHANGES package/COPYING package/README doc/*.html

OPTIONS_DEFINE=	DOCS
USE_CSTD=	c89

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS} -include unistd.h" > ${WRKSRC}/src/conf-cc
	@${ECHO_CMD} "${CC} ${LDFLAGS}" > ${WRKSRC}/src/conf-ld
	@${ECHO_CMD} "${LOCALBASE}/include/libdjbdns" \
		> ${WRKSRC}/src/conf-djbdnsinc
	@${ECHO_CMD} "${LOCALBASE}/lib" > ${WRKSRC}/src/conf-djbdnslib

do-build:
	cd ${WRKSRC} && package/compile && package/check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/sbin
.for n in 5 7 8
	${INSTALL_MAN} ${WRKSRC}/man/*.${n} ${STAGEDIR}${MANPREFIX}/man/man${n}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
