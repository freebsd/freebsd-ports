PORTNAME=	runas
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper around su for running a command as another user
WWW=		https://github.com/outpaddling/runas

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ARGS=	MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/asroot bin/runas share/man/man1/asroot.1.gz share/man/man1/runas.1.gz

.include <bsd.port.mk>
