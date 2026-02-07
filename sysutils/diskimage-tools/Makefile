PORTNAME=	diskimage-tools
DISTVERSION=	0.3.1-5
DISTVERSIONSUFFIX=	-g34f33d7
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Convenience tools for manipulating disk images
WWW=		https://github.com/outpaddling/diskimage-tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
NO_ARCH=	yes
MANPREFIX=	${PREFIX}/share

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
