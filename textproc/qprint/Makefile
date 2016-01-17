# $FreeBSD$

PORTNAME=	qprint
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.fourmilab.ch/webtools/qprint/

MAINTAINER=	takefu@airport.fm
COMMENT=	Encode and decode Quoted-Printable files

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/qprint \
		man/man1/qprint.1.gz

ALL_TARGET=	prog check wringer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qprint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qprint.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
