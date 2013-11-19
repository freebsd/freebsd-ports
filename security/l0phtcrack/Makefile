# Created by: trevor
# $FreeBSD$

PORTNAME=	l0phtcrack
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://www.mavetju.org/download/adopted/ \
		http://www.cotse.com/sw/WinNT/
DISTNAME=	lcsrc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cracks SAMBA or Windows NT passwords

USES=		dos2unix perl5
DOCDIR=		share/doc/${PORTNAME}
RESTRICTED=	uses GNU getopt with BSDish-licensed code from OpenSSL
NO_WRKSUBDIR=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_PERL5=	build

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} ${WRKDIR}/*exe
	${REINPLACE_CMD} -i '' -e 's|ommited|omitted|' ${WRKDIR}/util.c

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -DMPU8086 *.c -o lc_CLI

pre-install:
	${ECHO_CMD} bin/lc_CLI > ${PLIST}
	for i in `${FIND} ${WRKDIR} -name '*txt'`; \
		do ${ECHO_CMD} ${DOCDIR}/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lc_CLI ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${DOCDIR}
	cd ${WRKSRC} && ${PAX} -r -w *txt ${STAGEDIR}${PREFIX}/${DOCDIR}

.include <bsd.port.mk>
