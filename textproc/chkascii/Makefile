PORTNAME=	chkascii
DISTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	bourne.identity@hotmail.com
COMMENT=	Check an ASCII text file for invalid characters
WWW=		https://github.com/bourne-again/chkascii

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bourne-again

PLIST_FILES=	bin/chkascii \
		share/man/man1/chkascii.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chkascii ${STAGEDIR}${PREFIX}/bin/chkascii
	${INSTALL_MAN} ${WRKSRC}/chkascii.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
