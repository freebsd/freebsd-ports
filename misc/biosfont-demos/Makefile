PORTNAME=	biosfont-demos
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	misc
FJ_ACCOUNT=	rene0
FJ_PROJECT=	biosfont

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Demos for the biosfont kernel module

LICENSE=	BSD2CLAUSE

DEPRECATED=	No development in years
EXPIRATION_DATE=2026-12-31

USE_FORGEJO=	yes

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:sysutils/biosfont
RUN_DEPENDS=	/boot/modules/biosfont.ko:sysutils/biosfont

WRKSRC_SUBDIR=	biosfont-demos

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/show_char \
		bin/showdati

.include <bsd.port.mk>
