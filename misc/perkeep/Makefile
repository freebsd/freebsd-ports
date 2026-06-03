PORTNAME=	perkeep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Storage system: Storing, syncing, sharing, modelling, backing up files
WWW=		https://perkeep.org/ \
		https://github.com/perkeep/perkeep

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GO_MODULE=	perkeep.org

GO_TARGET=	${EXES:S/^/.\/cmd\//}

EXES=		pk pk-devimport pk-get pk-mount pk-put

PLIST_FILES=	${EXES:S/^/bin\//}

.include <bsd.port.mk>
