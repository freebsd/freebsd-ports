# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	anyterm
PORTVERSION=	1.1.29
CATEGORIES=	www
MASTER_SITES=	http://anyterm.org/download/ \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Terminal emulator on a Web page

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs

USE_RC_SUBR=	anytermd
USE_BZIP2=	yes
USES=		gmake iconv
USE_GCC=	any
ALL_TARGET=	default_target
PLIST_FILES=	man/man1/anytermd.1.gz \
		sbin/anytermd

post-patch:
	@${REINPLACE_CMD} -e 's|/private/etc/apache2|${FILESDIR}|' \
		${WRKSRC}/scripts/mimetype.sh
	@${REINPLACE_CMD} -e 's|^CPP_FLAGS=|&-I${LOCALBASE}/include |' \
		-e 's|^LINK_FLAGS=|&-L${ICONV_PREFIX}/lib ${ICONV_LIB} |' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|^COMPILE_FLAGS=|&-I${LOCALBASE}/include |' \
		${WRKSRC}/libpbe/common.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/anytermd ${STAGEDIR}${PREFIX}/sbin/anytermd
	@${INSTALL_MAN} ${WRKSRC}/anytermd.1 ${STAGEDIR}${MANPREFIX}/man/man1/anytermd.1

.include <bsd.port.mk>
