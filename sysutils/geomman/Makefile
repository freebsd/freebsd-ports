PORTNAME=	geomman
DISTVERSION=	1.0.1
CATEGORIES=	sysutils

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Interactive GEOM Manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbsddialog.so:devel/bsddialog

USES=		localbase:ldflags uidfix
USE_GITLAB=	yes
GL_ACCOUNT=	brauliorivas

MAKE_ENV=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/share/man/man

PLIST_FILES=	bin/geomman \
		share/man/man8/geomman.8.gz

.include <bsd.port.mk>
