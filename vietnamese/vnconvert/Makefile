PORTNAME=	vnconvert
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	vietnamese
MASTER_SITES=	LOCAL/obrien
DISTNAME=	convert
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Vietnamese text files between popular formats

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=

PLIST_FILES=	bin/vnconvert share/man/man1/vnconvert.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/vnconvert.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
