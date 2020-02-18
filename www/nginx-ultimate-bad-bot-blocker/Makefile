# $FreeBSD$

PORTNAME=		nginx-ultimate-bad-bot-blocker
DISTVERSION=		4.2020.02.1988
DISTFILES=		V${PORTVERSION}${EXTRACT_SUFX}
PORTREVISION=		0
CATEGORIES=		www security
MASTER_SITES=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Nginx bad bot and other things blocker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	gsed:textproc/gsed

USE_GITHUB=	nodefault

GH_ACCOUNT=	mitchellkrogza
GH_PROJECT=	${PORTNAME}

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
