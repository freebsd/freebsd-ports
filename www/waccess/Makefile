# Created by: tundra
# $FreeBSD$

PORTNAME=	waccess
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://www.tundraware.com/Software/waccess/

MAINTAINER=	tundra@tundraware.com
COMMENT=	Quick-N-Dirty Web Access Log Analyzer

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/waccess-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	waccess
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/waccess ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/waccess.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
