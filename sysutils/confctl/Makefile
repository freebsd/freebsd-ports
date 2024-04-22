PORTNAME=	confctl
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Utility to parse and modify C-like configuration files
WWW=		https://github.com/trasz/confctl/

LICENSE=	BSD2CLAUSE

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	trasz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
PLIST_FILES=	bin/confctl \
		share/man/man1/confctl.1.gz

.include <bsd.port.mk>
