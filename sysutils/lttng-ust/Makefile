# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=	lttng-ust
PORTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/${PORTNAME}/

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Libraries to instrument and trace user applications

LICENSE=		LGPL21 MIT GPLv2
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LIB_DEPENDS=	liburcu.so:sysutils/liburcu

USES=		autoreconf libtool localbase pathfix python \
	    shebangfix tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g' \
	    ${PATCH_WRKSRC}/tools/lttng-gen-tp

.include <bsd.port.mk>
