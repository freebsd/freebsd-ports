PORTNAME=	f3
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0
CATEGORIES=	sysutils

MAINTAINER=	chris.longros@gmail.com
COMMENT=	Fight Flash Fraud or Fight Fake Flash test tool
WWW=		https://oss.digirati.com.br/f3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		gmake localbase:ldflags pathfix shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	AltraMayor

SHEBANG_FILES=	scripts/f3write.h2w scripts/log-f3wr

LDFLAGS+=	-largp

PLIST_FILES=	bin/f3read bin/f3write bin/f3write.h2w \
		bin/log-f3wr share/man/man1/f3read.1.gz \
		share/man/man1/f3write.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/f3read ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/f3write ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/f3write.h2w ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/log-f3wr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/f3read.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/f3read.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/f3write.1

.include <bsd.port.mk>
