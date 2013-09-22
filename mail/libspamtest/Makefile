# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	libspamtest
PORTVERSION=	20080808
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Kaspersky Anti-Spam 3.x library

WRKSRC=		${WRKDIR}/libspamtest
MAKEFILE=	Makefile.FreeBSD

LIBS=		libspamtest.a \
		libspamtest_r.a
INCLUDES=	spamtest.h \
		msgstore.h

NO_STAGE=	yes

post-patch-script:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${PREFIX}/ap-mailfilter3/lib ${PREFIX}/ap-mailfilter3/include
	${INSTALL_DATA} ${LIBS:S,^,${WRKSRC}/,} ${PREFIX}/ap-mailfilter3/lib
	${INSTALL_DATA} ${INCLUDES:S,^,${WRKSRC}/,} \
		${PREFIX}/ap-mailfilter3/include

.include <bsd.port.mk>
