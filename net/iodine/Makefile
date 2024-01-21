PORTNAME=	iodine
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://code.kryo.se/iodine/

MAINTAINER=	p.mousavizadeh@protonmail.com
COMMENT=	Tunnel IPv4 data through a DNS server
WWW=		https://code.kryo.se/iodine/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	kryo
USE_RC_SUBR=	iodined

USERS=		_iodined
GROUPS=		_iodined

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/iodine.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.md CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
