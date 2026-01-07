PORTNAME=	iso-codes
DISTVERSION=	4.19.0
CATEGORIES=	misc
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lists of ISO standards, e.g. country, language, language scripts and currency names
WWW=		https://salsa.debian.org/iso-codes-team/iso-codes

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-tools gmake python:build shebangfix tar:xz
SHEBANG_FILES=	scripts/*.py

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' \
	    ${PATCH_WRKSRC}/*/Makefile.in
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' \
	   ${PATCH_WRKSRC}/common.mk

.include <bsd.port.mk>
