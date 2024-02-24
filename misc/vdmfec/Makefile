PORTNAME=	vdmfec
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc archivers
MASTER_SITES=	http://members.tripod.com/professor_tom/archives/

MAINTAINER=	freebsd@omnilan.de
COMMENT=	ECC wrapper using Vandermonde matrices based FEC
WWW=		https://members.tripod.com/professor_tom/archives/

LICENSE=	GPLv2

USES=		tar:tgz

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

PORTDOCS=	*

PLIST_FILES=	bin/vdm_decode \
		bin/vdm_encode \
		bin/vdmfec \
		share/man/man1/vdmfec.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.fec ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/vdmfec ${STAGEDIR}/${PREFIX}/bin
	${LN} ${STAGEDIR}/${PREFIX}/bin/vdmfec ${STAGEDIR}/${PREFIX}/bin/vdm_encode
	${LN} ${STAGEDIR}/${PREFIX}/bin/vdmfec ${STAGEDIR}/${PREFIX}/bin/vdm_decode
	${INSTALL_MAN} ${WRKSRC}/vdmfec.1 ${STAGEDIR}/${PREFIX}/share/man/man1/

.include <bsd.port.mk>
