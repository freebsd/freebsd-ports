PORTNAME=	freecolor
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/freecolor/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Displays free memory as a bargraph
WWW=		https://www.rkeene.org/oss/freecolor/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKE_ENV+=	INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USES=		pkgconfig

PLIST_FILES=	bin/freecolor share/man/man1/freecolor.1.gz

.include <bsd.port.mk>
