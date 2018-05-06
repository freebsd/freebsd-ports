# $FreeBSD$

PORTNAME=	c2man
PORTVERSION=	${VERSION}.${PATCHLEVEL}
CATEGORIES=	textproc
MASTER_SITES=	http://www.ciselant.de/${PORTNAME}/
DISTNAME=	${PORTNAME}-${VERSION}@${PATCHLEVEL}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Tool to generate documentation from C source code comments

LICENSE=	${PORTNAME}
LICENSE_NAME=	${PORTNAME}
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Not recommended for use in new projects

VERSION=	2.0
PATCHLEVEL=	42

NO_WRKSUBDIR=	yes
NO_INSTALL=	yes

PLIST_FILES=	bin/c2man man/man1/c2man.1.gz

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-des -Dcc="${CC}" -Dccflags="${CFLAGS}" -Dldflags="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
