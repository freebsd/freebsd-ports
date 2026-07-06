PORTNAME=	cyrus-imapd
PORTVERSION=	3.12
PORTREVISION=	0
CATEGORIES=	mail

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Meta-port for the latest version of Cyrus mail server
WWW=		https://www.cyrusimap.org/

FLAVORS=        basic http
http_PKGNAMESUFFIX=	-${FLAVOR}

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/cyrus/libexec/master:mail/cyrus-imapd312@${FLAVOR}

.include <bsd.port.mk>
