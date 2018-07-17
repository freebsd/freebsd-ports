# Created by: tundra
# $FreeBSD$

PORTNAME=	tdir
PORTVERSION=	1.71
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	tdir@tundraware.com
COMMENT=	Advanced file directory display utility

BROKEN=		license forbids modification, but the port cannot be used without it
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2018-08-20

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/tdir-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell no-auto-accept

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	tdir
python_OLD_CMD=	"/usr//bin/env python"
NO_ARCH=	yes

PLIST_FILES=	bin/tdir \
		man/man1/tdir.1.gz

.include <bsd.port.mk>
