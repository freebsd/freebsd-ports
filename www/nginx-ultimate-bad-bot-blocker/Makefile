# $FreeBSD$

PORTNAME=		nginx-ultimate-bad-bot-blocker
DISTVERSIONPREFIX=	V
# The config files are updated frequently (not installed by this port,
# but by install-ngxblocker / update-ngxblocker).
# The scripts (installed by this port) are not updated frequently.
# The version number of the project is related to the combination of
# scripts and config. As such a more recent upstream version is most
# of the time OK (as long as you use update-ngxblocker in crontab).
DISTVERSION=		4.2020.03.2005
PORTREVISION=		1
CATEGORIES=		www security

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Nginx bad bot and other things blocker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	curl:ftp/curl \
		gsed:textproc/gsed \
		wget:ftp/wget

USE_GITHUB=	yes

GH_ACCOUNT=	mitchellkrogza

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	sbin/install-ngxblocker \
		sbin/setup-ngxblocker \
		sbin/update-ngxblocker

post-patch:
	${REINPLACE_CMD} -e 's:/usr/local:${PREFIX}:g' \
		-e 's:/etc/nginx:${LOCALBASE}/etc/nginx:g' \
		-e 's:nginx/sites-available:nginx/sites:g' \
		-e 's:/var/www:${LOCALBASE}/www:g' \
		-e 's:VHOST_EXT="vhost":VHOST_EXT="conf":' ${WRKSRC}/*-ngxblocker

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*-ngxblocker ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
