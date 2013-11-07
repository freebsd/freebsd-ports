# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	fpart
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/fpart/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Sort and pack files into partitions

LICENSE=	BSD

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-embfts

PLIST_FILES=	bin/fpart man/man1/fpart.1.gz
PORTDOCS=	Changelog README TODO

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
