# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	anyterm
PORTVERSION=	1.1.29
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://anyterm.org/download/ \
		http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Terminal emulator on a Web page

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:devel/boost-libs

BROKEN_powerpc64=	Does not build

USE_RC_SUBR=	anytermd
USES=		gmake iconv localbase tar:tbz2
USE_GCC=	any
ALL_TARGET=	default_target
PLIST_FILES=	man/man1/anytermd.1.gz \
		sbin/anytermd

post-patch:
	@${REINPLACE_CMD} -e 's|/private/etc/apache2|${FILESDIR}|' \
		${WRKSRC}/scripts/mimetype.sh
	@${REINPLACE_CMD} \
		-e 's|$$(CPP_FLAGS)|& ${CPPFLAGS} |' \
		-e '/^COMPILE_FLAGS=/s|$$| ${CXXFLAGS}|' \
		-e 's|$${OPTIMISE_FLAGS}||' \
		-e 's|$$(LINK_FLAGS)|& -L${ICONV_PREFIX}/lib ${ICONV_LIB} |' \
		${WRKSRC}/common.mk
	@${REINPLACE_CMD} \
		-e '/^COMPILE_FLAGS=/s|$$| ${CXXFLAGS}|' \
		-e 's|$$(INC_FLAGS)|& ${CPPFLAGS} |' \
		-e 's|$$(CXXFLAGS)||' -e 's|$$(OPTIMISE_FLAGS)||' \
		${WRKSRC}/libpbe/common.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/anytermd ${STAGEDIR}${PREFIX}/sbin/anytermd
	${INSTALL_MAN} ${WRKSRC}/anytermd.1 ${STAGEDIR}${MANPREFIX}/man/man1/anytermd.1

.include <bsd.port.mk>
