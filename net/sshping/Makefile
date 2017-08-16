# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshping
PORTVERSION=	0.0.2017081601
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SSH-based ping to measure character echo latency and bandwidth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh.so:security/libssh

USES=		compiler:c++14-lang localbase:ldflags
USE_GITHUB=	yes

GH_ACCOUNT=	spook
GH_TAGNAME=	0856aa5

LDFLAGS+=	-lssh

PLIST_FILES=	bin/sshping

do-build:
	${CXX} ${CXXFLAGS} ${LDFLAGS} -I ${WRKSRC}/ext \
		${WRKSRC}/src/sshping.cxx -o ${WRKSRC}/bin/sshping

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
