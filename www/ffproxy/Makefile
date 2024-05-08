PORTNAME=	ffproxy
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/${PORTNAME}/ \
		http://www.nevm.de/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filtering HTTP proxy server
WWW=		https://ffproxy.sourceforge.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned upstream, last update in 2006. Consider using www/squid
EXPIRATION_DATE=2024-06-30

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
