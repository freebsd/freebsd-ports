PORTNAME=	typst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Markup-based typesetting system
WWW=		https://typst.app/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
