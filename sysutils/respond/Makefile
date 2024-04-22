PORTNAME=	respond
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	j.witteveen@gmail.com
COMMENT=	Response automator for logged events
WWW=		https://github.com/joukewitteveen/respond

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	joukewitteveen

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANPREFIX="${PREFIX}/share"

.include <bsd.port.mk>
