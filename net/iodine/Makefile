PORTNAME=	iodine
DISTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	https://code.kryo.se/iodine/

MAINTAINER=	pouria@FreeBSD.org
COMMENT=	Tunnel IPv4 data through a DNS server
WWW=		https://code.kryo.se/iodine/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:indirect cpe meson
CPE_VENDOR=	kryo
USE_RC_SUBR=	iodined

USERS=		_iodined
GROUPS=		_iodined

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.md CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
