# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	fpart
PORTVERSION=	0.8
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/fpart/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Sort and pack files into partitions

LICENSE=	BSD

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-embfts

MANCOMPRESSED=	no
MAN1=		fpart.1
PLIST_FILES=	bin/fpart
PORTDOCS=	Changelog README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
