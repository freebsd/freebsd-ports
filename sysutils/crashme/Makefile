PORTNAME=	crashme
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/kris
DISTNAME=	crashme

MAINTAINER=	gjc@alum.mit.edu
COMMENT=	Tool to test an operating system's robustness
WWW=		http://crashme.codeplex.com/

# according to license.rtf, and using the most restrictive one:
LICENSE=	LGPL21

USES=		gmake tar:tgz
NO_WRKSUBDIR=	yes

MAKEFILE=	makefile
PLIST_FILES=	bin/crashme bin/pddet share/man/man1/crashme.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crashme ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pddet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/crashme.man \
		${STAGEDIR}${PREFIX}/share/man/man1/crashme.1

.include <bsd.port.mk>
