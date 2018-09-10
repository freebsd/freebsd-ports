# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iodine
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://code.kryo.se/iodine/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tunnel IPv4 data through a DNS server

LICENSE=	ISCL

USES=		cpe
CPE_VENDOR=	kryo
USE_RC_SUBR=	iodined

USERS=		_iodined
GROUPS=		_iodined

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/iodine.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${GZIP_CMD} ${STAGEDIR}${MANPREFIX}/man/man8/iodine.8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README CHANGELOG TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
