PORTNAME=	shellharden
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.0
PORTREVISION=	9
CATEGORIES=	shells

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Corrective bash syntax highlighter
WWW=		https://github.com/anordal/shellharden

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	anordal

CARGO_CRATES=	\

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
