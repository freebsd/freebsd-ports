# New ports collection makefile for:	y4mscaler
# Date created:		Mon Mar  8 21:36:23 EST 2004
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	y4mscaler
PORTVERSION=	8.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mir.com/DMG/Software/
DISTNAME=	${PKGNAME}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Y4mscaler scales, crops, and shifts Y'CbCr video

LIB_DEPENDS=	lavjpeg-1.6.3:${PORTSDIR}/multimedia/mjpegtools

USE_REINPLACE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}

PORTDOCS=	COPYING ChangeLog INSTALL README TODO
MAN1=		y4mscaler.1
PLIST_FILES=	bin/y4mscaler
MAKE_ENV=	CXX="${CXX}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|COPT = -O2|#|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS =|CXXFLAGS = ${CXXFLAGS} |' \
		${WRKSRC}/Makefile
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|#define HAVE_STDINT_H 1|#undef HAVE_STDINT_H 1|' \
		${WRKSRC}/y4m-config.h
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/y4mscaler ${PREFIX}/bin/y4mscaler
	@${INSTALL_MAN} ${WRKSRC}/y4mscaler.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
