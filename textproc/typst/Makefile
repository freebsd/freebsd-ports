PORTNAME=	typst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	textproc
#MASTER_SITES=	https://github.com/typst/svg2pdf/blob/35f4bb87fb677473661c6d12919e01a6d64a716d/:source1
#DISTFILES+=	svg2pdf-${SVG2PDF_COMMIT}.tar.gz:source1

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Markup-based typesetting system
WWW=		https://typst.app/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes

SVG2PDF_COMMIT=	35f4bb87fb677473661c6d12919e01a6d64a716d

PLIST_FILES=	bin/${PORTNAME}

post-extract:
#	${REINPLACE_CMD} "s?0\.22\.0?0\.32\.0?g" \
#		 ${WRKSRC}/cargo-crates/svg2pdf-0.4.1/Cargo.lock
#	${REINPLACE_CMD} "s?0\.22?0\.32?g" \
#		${WRKSRC}/cargo-crates/svg2pdf-0.4.1/Cargo.toml

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/*/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
