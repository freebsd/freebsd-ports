# ex:ts=8
# Ports collection makefile for:	libharu
# Date created:			Jun 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libharu
PORTVERSION=	2.0.8
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--shared \
		--prefix=${PREFIX} \
		--cflags="${CFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

PLIST_FILES=	include/hpdf.h \
		include/hpdf_consts.h \
		include/hpdf_types.h \
		lib/libhpdf.so \
		lib/libhpdf.so.1 \
		lib/libhpdf.so.1.0.0

.if !defined(NOPORTDOCS)
PORTDOCS=	*

post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
