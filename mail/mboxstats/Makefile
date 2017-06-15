# Created by: clsung
# $FreeBSD$

PORTNAME=	mboxstats
PORTVERSION=	3.1
CATEGORIES=	mail
MASTER_SITES=	http://vanheusden.com/mboxstats/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates top-10 lists of the messages in a mailbox

LICENSE=	GPLv2

USES=		tar:tgz

PLIST_FILES=	bin/mboxstats

post-patch:
	@${REINPLACE_CMD} -e 's|ssize_t|size_t|g' ${WRKSRC}/io.h
	@${REINPLACE_CMD} -e 's|PATH_MAX|FILENAME_MAX|g' ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's|^CC=|CC?=|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CPPFLAGS|CXXFLAGS|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -Ee 's,(stat|open)64,\1,g' ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -Ee 's,(stat|mmap|lseek|off)64,\1,g' ${WRKSRC}/br.h \
		${WRKSRC}/br.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mboxstats ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
