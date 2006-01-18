# New ports collection makefile for:	rssyl
# Date created:				17 December 2005
# Whom:					v.velox@vvelox.net
#
# $FreeBSD$
#

PORTNAME=	rssyl
PORTVERSION=	0.3
CATEGORIES=	mail
MASTER_SITES=	http://ticho.yweb.sk/rssyl/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	v.velox@vvelox.net
COMMENT=	A RSS/Atom plugin for sylheed-claws

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws:${PORTSDIR}/mail/sylpheed-claws

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/100\.93/100/' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
