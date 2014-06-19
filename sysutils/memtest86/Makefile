# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	memtest86
PORTVERSION=	4.0b
CATEGORIES=	sysutils
MASTER_SITES=	http://www.memtest86.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/s/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.iso.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stand alone memory test for x86 architecture computers

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
ISO=		Memtest86_${PORTVERSION:S/b/s/}.iso
ISODEST=	Memtest86_${PORTVERSION:S/b//}.iso

PORTDOCS=	README
PLIST_FILES=	%%DATADIR%%/floppy.bin \
		%%DATADIR%%/${ISODEST}
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/precomp.bin ${STAGEDIR}${DATADIR}/floppy.bin
	${INSTALL_DATA} ${WRKDIR}/${ISO} ${STAGEDIR}${DATADIR}/${ISODEST}
.for i in ${PORTDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
