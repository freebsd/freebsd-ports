PORTNAME=	afdko
PORTVERSION=	3.9.5
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/adobe-type-tools/afdko/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adobe Font Development Kit for OpenType (AFDKO)
WWW=		https://github.com/adobe-type-tools/afdko

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang gnome
USE_GNOME=	libxml2

CMAKE_OFF=	SKBUILD

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
