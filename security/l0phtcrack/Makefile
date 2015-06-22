# Created by: trevor
# $FreeBSD$

PORTNAME=	l0phtcrack
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.mavetju.org/download/adopted/
#		http://www.cotse.com/sw/WinNT/
DISTNAME=	lcsrc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cracks SAMBA or Windows NT passwords

USES=		dos2unix perl5 zip
USE_PERL5=	build
RESTRICTED=	uses GNU getopt with BSDish-licensed code from OpenSSL
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/lc_CLI
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} ${WRKDIR}/*exe
	${REINPLACE_CMD} -i '' -e 's|ommited|omitted|' ${WRKDIR}/util.c

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -DMPU8086 *.c -o lc_CLI

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lc_CLI ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${PAX} -r -w *txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
