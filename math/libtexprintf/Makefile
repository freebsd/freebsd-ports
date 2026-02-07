PORTNAME=	libtexprintf
DISTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	math textproc
MASTER_SITES=	https://github.com/bartp5/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Formatted math formula output with tex-like syntax
WWW=		https://github.com/bartp5/libtexprintf

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
