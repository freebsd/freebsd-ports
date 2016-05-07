# $FreeBSD$

PORTNAME=	ab25
PORTVERSION=	0.2.5
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for ARIB STD-B25 ECM handling in MPEG2-TS stream

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/licence.txt

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/FreeBSD/libccid.so:devel/libccid

USES=		uidfix
USE_LDCONFIG=	yes
PORTDOCS=	README readme-en.txt readme-jp.txt

PLIST_FILES=	bin/b25 \
		lib/libab25.a lib/libab25_p.a lib/libab25.so.1 lib/libab25.so \
		include/ab25/arib_std_b25.h include/ab25/b_cas_card.h

OPTIONS_DEFINE=	DOCS

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ab25

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
