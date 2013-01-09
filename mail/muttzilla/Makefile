# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	muttzilla
PORTVERSION=	0.40
CATEGORIES=	mail www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mutt MUA plugin for Netscape for use on "mailto:" URLs

pre-configure:
	@${REINPLACE_CMD} \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/muttzilla.h ${WRKSRC}/mzmail.sh ${WRKSRC}/mzmail.py \
		${WRKSRC}/mznews.sh ${WRKSRC}/mznews.py

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.mk>
