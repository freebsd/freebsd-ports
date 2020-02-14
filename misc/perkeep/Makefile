# $FreeBSD$

PORTNAME=	perkeep
DISTVERSION=	0.10.20190926
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Storage system: Storing, syncing, sharing, modelling, backing up files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_TAGNAME=	d342b0e # master branch doesn't contain 0.10

GO_TARGET=	${EXES:S/^/.\/cmd\//}

EXES=		pk pk-deploy pk-devimport pk-get pk-mount pk-put

PLIST_FILES=	${EXES:S/^/bin\//}

# https://github.com/perkeep/perkeep/issues/1302
post-extract:
	@${RM} ${WRKSRC}/vendor/modules.txt

.include <bsd.port.mk>
