# Created by: rene
# $FreeBSD$

PORTNAME=	biosfont-demos
PORTVERSION=	1.3
CATEGORIES=	misc

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Demos for the biosfont kernel module

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:sysutils/biosfont
RUN_DEPENDS=	/boot/modules/biosfont.ko:sysutils/biosfont

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_PROJECT=	biosfont
WRKSRC_SUBDIR=	biosfont-demos

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/show_char bin/showdati

.include <bsd.port.mk>
