PORTNAME=	mautrix-whatsapp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2512.0
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	juw@posteo.de
COMMENT=	Matrix-WhatsApp puppeting bridge
WWW=		https://maunium.net/go/mautrix-whatsapp/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../../LICENSE

LIB_DEPENDS=	libolm.so:security/olm

USES=		go:modules
USE_RC_SUBR=	mautrix_whatsapp

GO_MODULE=	go.mau.fi/mautrix-whatsapp

WRKSRC_SUBDIR=	cmd/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR} \
		 ${STAGEDIR}/var/log/mautrix-whatsapp

.include <bsd.port.mk>
