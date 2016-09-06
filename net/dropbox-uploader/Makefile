# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dropbox-uploader
PORTVERSION=	0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	BASH script for the Dropbox backup service

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		greadlink:sysutils/coreutils

USE_GITHUB=	yes
GH_ACCOUNT=	andreafabrizi
GH_PROJECT=	Dropbox-Uploader
GH_TAGNAME=	856c10a

NO_BUILD=	yes

PLIST_FILES=	bin/dropShell.sh bin/dropbox_uploader.sh

post-patch:
	${REINPLACE_CMD} -E -e 's,("darwin"),\1 -o "$${OSTYPE:0:7}" == "freebsd" ,1' -i.bak ${WRKSRC}/dropShell.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/drop*.sh ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
