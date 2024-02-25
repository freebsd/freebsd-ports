PORTNAME=	damager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	amijaresp@gmail.com
COMMENT=	Overrides chunks of files with garbage
WWW=		https://github.com/granalberto/damager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	granalberto

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/damager \
		share/man/man1/damager.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
