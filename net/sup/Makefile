# Created by: jkh
# $FreeBSD$

PORTNAME=	sup
PORTVERSION=	2.0.20200824
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	CMU's Software Update Protocol package

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd

# XXX Static libraries with PIE are currently unsupported.
MAKE_ARGS+=	WITHOUT_PIE=true

PLIST_FILES=	bin/sup bin/supfilesrv bin/supscan \
		man/man1/sup.1.gz man/man8/supfilesrv.8.gz \
		man/man8/supscan.8.gz man/man8/supservers.8.gz

.include <bsd.port.mk>
