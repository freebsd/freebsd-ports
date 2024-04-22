PORTNAME=	bsod
DISTVERSIONPREFIX=v
DISTVERSION=	0.2
CATEGORIES=	misc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Experience the authentic Microsoft Windows experience
WWW=		https://github.com/folkertvanheusden/bsod

LICENSE=	PD

USES=		ncurses tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	folkertvanheusden

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DVERSION=\"${DISTVERSION}\" -I${NCURSESINC} -L${NCURSESLIB} -lncurses -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
