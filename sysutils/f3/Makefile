PORTNAME=	f3
PORTVERSION=	8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Fight Flash Fraud or Fight Fake Flash test tool
WWW=		https://oss.digirati.com.br/f3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		gmake localbase:ldflags pathfix shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	AltraMayor

LDFLAGS+=	-largp

PLIST_FILES=	bin/f3read bin/f3write bin/f3write.h2w \
		bin/log-f3wr share/man/man1/f3read.1.gz

SHEBANG_FILES=	f3write.h2w log-f3wr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/f3read ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/f3write ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/f3write.h2w ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/log-f3wr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/f3read.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
