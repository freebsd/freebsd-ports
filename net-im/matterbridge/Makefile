PORTNAME=	matterbridge
PORTVERSION=	1.22.3
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	net-im

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Chat network bridge
WWW=		https://github.com/42wim/matterbridge

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	42wim
GH_TUPLE=	golang:sys:v0.6.0:sys

USE_RC_SUBR=	matterbridge

MATTERBRIDGE_USER?=	mattermost
MATTERBRIDGE_GROUP?=	mattermost
USERS=		${MATTERBRIDGE_USER}
GROUPS=		${MATTERBRIDGE_GROUP}
SUB_LIST=	\
		MATTERBRIDGE_USER=${MATTERBRIDGE_USER} \
		MATTERBRIDGE_GROUP=${MATTERBRIDGE_GROUP}
PLIST_SUB=	\
		MATTERBRIDGE_USER=${MATTERBRIDGE_USER} \
		MATTERBRIDGE_GROUP=${MATTERBRIDGE_GROUP}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA} ${WRKSRC}/matterbridge.toml.sample ${STAGEDIR}${PREFIX}/etc/matterbridge.toml.sample

.include <bsd.port.mk>
