PORTNAME=	typst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Markup-based typesetting system
WWW=		https://typst.app/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LTO_UNSAFE=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/*/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
