# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	libeatmydata
PORTVERSION=	9
CATEGORIES=	misc
MASTER_SITES=	http://www.flamingspork.com/projects/libeatmydata/

MAINTAINER=	bra@fsn.hu
COMMENT=	Small library designed to transparently disable fsync

USES=		tar:bzip2
NO_MTREE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libeatmydata.so \
		lib/libeatmydata.so.1 \
		lib/libeatmydata.so.1.0

post-patch:
	${SED} -i '' -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libeatmydata.so.1.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libeatmydata.so.1.0 ${STAGEDIR}${PREFIX}/lib/libeatmydata.so.1
	${LN} -sf libeatmydata.so.1.0 ${STAGEDIR}${PREFIX}/lib/libeatmydata.so

.include <bsd.port.mk>
