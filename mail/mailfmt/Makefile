# Created by: tundra
# $FreeBSD$

PORTNAME=	mailfmt
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.tundraware.com/Software/mailfmt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remove leading quotations from mail/news and wrap lines to fixed width

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/mailfmt-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-auto-accept

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	mailfmt
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
