PORTNAME=	devstat
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Utility to display device statistics

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	trociny

MAKE_ENV+=	NO_OBJ=yes

PLIST_FILES=	bin/devstat \
		man/man8/devstat.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/devstat ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/devstat.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
