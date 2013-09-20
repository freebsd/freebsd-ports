# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	anyterm
PORTVERSION=	1.1.29
CATEGORIES=	www
MASTER_SITES=	http://anyterm.org/download/ \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	A terminal emulator on a Web page

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs

MAN1=		anytermd.1
USE_RC_SUBR=	anytermd
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		iconv
USE_GCC=	any
ALL_TARGET=	default_target
PLIST_FILES=	sbin/anytermd

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/private/etc/apache2|${FILESDIR}|' \
		${WRKSRC}/scripts/mimetype.sh
	@${REINPLACE_CMD} -e 's|^CPP_FLAGS=|&-I${LOCALBASE}/include |' \
		-e 's|^LINK_FLAGS=|&-L${LOCALBASE}/lib |' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|^COMPILE_FLAGS=|&-I${LOCALBASE}/include |' \
		${WRKSRC}/libpbe/common.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/anytermd ${PREFIX}/sbin/anytermd
	@${INSTALL_MAN} ${WRKSRC}/anytermd.1 ${MANPREFIX}/man/man1/anytermd.1

.include <bsd.port.mk>
