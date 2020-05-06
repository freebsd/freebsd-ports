# $FreeBSD$

PORTNAME=	poshinit
PORTVERSION=	2.0
CATEGORIES=	shells

MAINTAINER=	bourne.identity@hotmail.com
COMMENT=	Portable shell setup for Bash/Zsh across FreeBSD/Linux/Cygwin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bourne-again

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
