# Created by: Yi-Hsuan Hsin <mhsin@mhsin.org>
# $FreeBSD$

PORTNAME=	tivodecode
DISTVERSION=	0.2pre4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2pre4

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Converts .TiVo files to normal MPEG files

OPTIONS_DEFINE=	DOCS

USES=		gmake
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
