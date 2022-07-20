PORTNAME=	mp4box
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	multimedia
PKGNAMEPREFIX=	gpac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for merge mpg4 from Gpac

LICENSE=	LGPL21

LIB_DEPENDS=	libgpac.so:multimedia/gpac-libgpac

USES=		cpe localbase:ldflags

CPE_VENDOR=	gpac

USE_GITHUB=	yes
GH_ACCOUNT=	gpac
GH_PROJECT=	gpac

LDFLAGS+=	-lgpac

WRKSRC_SUBDIR=	applications/mp4box
PLIST_FILES=	bin/mp4box man/man1/mp4box.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o mp4box \
		filedump.c fileimport.c live.c main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp4box ${STAGEDIR}${PREFIX}/bin/mp4box
	${INSTALL_MAN} ${WRKSRC}/../../share/doc/man/mp4box.1 \
		${STAGEDIR}${PREFIX}/man/man1/mp4box.1

.include <bsd.port.mk>
