PORTNAME=	libtexprintf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.25
CATEGORIES=	math textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Formatted math formula output with tex-like syntax
WWW=		https://github.com/bartp5/libtexprintf

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bartp5

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
