PORTNAME=	wait_on
DISTVERSION=	1.1-2
DISTVERSIONSUFFIX=	-g2fb6f24
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jcpierri@gmail.com
COMMENT=	Enable shell scripts to monitor for changes on directories and files
WWW=		https://github.com/jcpierri/wait_on

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	jcpierri

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	bin/wait_on share/man/man1/wait_on.1.gz

.include <bsd.port.mk>
