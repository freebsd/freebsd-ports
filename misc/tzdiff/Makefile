PORTNAME=	tzdiff
DISTVERSION=	1.2.1
CATEGORIES=	misc

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Showing time pairs between target timezone and localtime
WWW=		https://github.com/belgianbeer/tzdiff

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	belgianbeer

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/tzdiff \
		share/man/man1/tzdiff.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tzdiff \
	    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tzdiff.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
