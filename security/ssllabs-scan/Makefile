PORTNAME=		ssllabs-scan
DISTVERSIONPREFIX=	v
DISTVERSION=		1.5.0
PORTREVISION=	29
CATEGORIES=		security net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Command-line tool to use the SSL Labs API
WWW=		https://www.ssllabs.com/projects/ssllabs-apis/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	ssllabs

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
