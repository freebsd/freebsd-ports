PORTNAME=	gping
DISTVERSIONPREFIX=	gping-v
DISTVERSION=	1.19.0
PORTREVISION=	5
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ping with graph
WWW=		https://github.com/orf/gping

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	orf

PLIST_FILES=	bin/gping \
		share/man/man1/gping.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gping.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
