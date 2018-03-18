# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshping
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SSH-based ping to measure character echo latency and bandwidth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh.so:security/libssh

USES=		localbase:ldflags perl5
USE_GITHUB=	yes
USE_PERL5=	build

GH_ACCOUNT=	spook

LDFLAGS+=	-lssh

PLIST_FILES=	bin/sshping man/man1/sshping.1.gz

do-build:
	${CXX} ${CXXFLAGS} ${LDFLAGS} -I ${WRKSRC}/ext \
		${WRKSRC}/src/sshping.cxx -o ${WRKSRC}/bin/sshping
	@pod2man ${WRKSRC}/doc/${PORTNAME}.pod ${WRKSRC}/doc/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
