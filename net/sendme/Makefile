PORTNAME=		sendme
DISTVERSIONPREFIX=	v
DISTVERSION=		0.26.0
PORTREVISION=	2
CATEGORIES=		net

MAINTAINER=		feld@FreeBSD.org
COMMENT=		Like scp without needing to know the IP address
WWW=			https://www.iroh.computer/sendme

LICENSE=		APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	n0-computer

PLIST_FILES=	bin/sendme

.include <bsd.port.mk>
