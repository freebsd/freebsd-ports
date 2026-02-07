PORTNAME=	progress
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Show progress for various command-line programs
WWW=		https://github.com/Xfennec/progress

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Xfennec

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
