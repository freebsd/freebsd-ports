# ex:ts=8
# New ports collection makefile for:	mboxstats
# Date created:			Oct 31 2003
# Whom:				clsung
#
# $FreeBSD$
#

PORTNAME=	mboxstats
PORTVERSION=	2.9
CATEGORIES=	mail
MASTER_SITES=	http://vanheusden.com/mboxstats/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Creates top-10 lists of the messages in a mailbox

PLIST_FILES=	bin/mboxstats
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386 alpha

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|ssize_t|size_t|g' ${WRKSRC}/io.h
	@${REINPLACE_CMD} -e 's|PATH_MAX|FILENAME_MAX|g' ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's|^CC=|CC?=|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CPPFLAGS|CXXFLAGS|g' ${WRKSRC}/${MAKEFILE}
.if ${ARCH} == "i386" || ${ARCH} == "alpha"
	@${REINPLACE_CMD} -Ee 's,(stat|open)64,\1,g' ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -Ee 's,(stat|mmap|lseek|off)64,\1,g' ${WRKSRC}/br.h ${WRKSRC}/br.cpp
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mboxstats ${PREFIX}/bin

.include <bsd.port.post.mk>
