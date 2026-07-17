PORTNAME=	sasso
DISTVERSION=	0.8.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/momiji-rs/sasso/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Fast and conformant Sass to CSS compiler
WWW=		https://github.com/momiji-rs/sasso

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo tar:xz

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
