PORTNAME=	biosfont-demos
PORTVERSION=	1.3.1
CATEGORIES=	misc
MASTER_SITES=  https://codeberg.org/rene0/biosfont/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Demos for the biosfont kernel module
WWW=		https://codeberg.org/rene0/biosfont

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:sysutils/biosfont
RUN_DEPENDS=	/boot/modules/biosfont.ko:sysutils/biosfont

WRKSRC=		${WRKDIR}/biosfont
WRKSRC_SUBDIR=	biosfont-demos

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/show_char bin/showdati

.include <bsd.port.mk>
