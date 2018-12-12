# $FreeBSD$

PORTNAME=	chkascii
DISTVERSION=	1.2
CATEGORIES=	textproc

MAINTAINER=	bourne.identity@hotmail.com
COMMENT=	Check an ASCII text file for invalid characters

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bourne-again

PLIST_FILES=	bin/chkascii \
		man/man1/chkascii.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chkascii ${STAGEDIR}${PREFIX}/bin/chkascii
	${INSTALL_MAN} ${WRKSRC}/chkascii.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
