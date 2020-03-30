# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	git-remote-gcrypt
PORTVERSION=	1.3
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	PGP-encrypt git remotes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	rsync:net/rsync \
		curl:ftp/curl \
		gpg:security/gnupg

USES=		python:build
USE_GITHUB=	yes
GH_ACCOUNT=	spwhitton
MAKE_ENV=	DESTDIR=${STAGEDIR}

NO_BUILD=

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-extract:
	@${REINPLACE_CMD} -e s,prefix/share/man,prefix/man, ${WRKSRC}/install.sh

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${WRKSRC}/install.sh

.include <bsd.port.mk>
