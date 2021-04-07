PORTNAME=	ylva
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line password manager and file encryption program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase:ldflags sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nrosvall

MAKE_ENV=	MANDIR=${PREFIX}/man

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
