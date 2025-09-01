PORTNAME=	mdbook-linkcheck
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.7
PORTREVISION=	27
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mdBook backend to check links
WWW=		https://github.com/Michael-F-Bryan/mdbook-linkcheck

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Michael-F-Bryan
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/native-tls/s/-vendored//' \
		${WRKSRC}/Cargo.toml

.include <bsd.port.mk>
