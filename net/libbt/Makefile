# New ports collection makefile for:	libbt
# Date created:				Feb 26 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	libbt
PORTVERSION=	0.02
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@xbsd.org
COMMENT=	C library implementing the core BitTorrent protocol

LIB_DEPENDS=	uuid.1:${PORTSDIR}/sysutils/e2fsprogs \
		curl.2:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbt.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/libbt
.for i in benc.h bitset.h bterror.h bts.h context.h peer.h random.h segmenter.h strbuf.h stream.h types.h util.h
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${PREFIX}/include/libbt
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/protocol.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
