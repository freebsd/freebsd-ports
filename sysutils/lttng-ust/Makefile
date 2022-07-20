PORTNAME=	lttng-ust
PORTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries to instrument and trace user applications

LICENSE=		LGPL21 MIT GPLv2
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

BROKEN=		fails to configure: Cannot find liburcu-bp lib. Use LDFLAGS=-Ldir to specify its location

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
LIB_DEPENDS=	liburcu.so:sysutils/liburcu

USES=		autoreconf gmake libtool localbase pathfix python \
		shebangfix tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
# XXX: build fails if cmake is detected, see PR 253327
CONFIGURE_ENV=	ac_cv_prog_HAVE_CMAKE=no
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	tools/lttng-gen-tp
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -Rl --null '#!/bin/bash' ${WRKSRC}/tests | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/#!/s,bash,sh,'

.include <bsd.port.mk>
