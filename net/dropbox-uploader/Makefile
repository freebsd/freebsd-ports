# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dropbox-uploader
PORTVERSION=	0.12
#PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	BASH script for the Dropbox backup service

LICENSE=	GPLv3

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		curl:${PORTSDIR}/ftp/curl \
		greadlink:${PORTSDIR}/sysutils/coreutils

GH_ACCOUNT=	andreafabrizi
GH_COMMIT=	3e5aef0
GH_PROJECT=	Dropbox-Uploader
GH_TAGNAME=	${GH_COMMIT}

NO_BUILD=	yes

PLIST_FILES=	bin/dropShell.sh bin/dropbox_uploader.sh

USE_GITHUB=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -E -e 's,("darwin9"),\1 -o "$${OSTYPE:0:7}" == "freebsd" ,1' -i.bak ${WRKSRC}/dropShell.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${PREFIX}/bin/

.include <bsd.port.mk>
