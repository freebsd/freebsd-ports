# New ports collection makefile for:	mkclean
# Date created:		2010-10-24
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mkclean
PORTVERSION=	0.8.6
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Clean and optimize Matroska and WebM files

LICENSE=	BSD

USE_BZIP2=	yes
HAS_CONFIGURE=	yes

USE_GMAKE=	yes
USE_ICONV=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

MAKE_ENV+=	"LFLAGS=${LDFLAGS}"
MAKEFILE=	GNUmakefile
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/mkclean

post-extract:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/corec/tools/coremake/gcc_mak.inc
	@${RM} ${WRKSRC}/libmatroska2/test/test.proj

.include <bsd.port.mk>
