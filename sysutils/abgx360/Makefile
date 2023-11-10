PORTNAME=	abgx360
PORTVERSION=	1.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://abgx360.hadzz.com/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Verify and repair Xbox 360 backup images
WWW=		http://abgx360.hadzz.com/

LICENSE=	NONE

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/abgx360

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abgx360 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
