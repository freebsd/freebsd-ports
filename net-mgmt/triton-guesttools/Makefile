# $FreeBSD$

PORTNAME=	triton-guesttools
PORTVERSION=	0.0.0.0s2017111501
CATEGORIES=	net-mgmt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	FreeBSD guest tools for use with SmartOS

RUN_DEPENDS=	bash:shells/bash \
		mdata-client>0:net-mgmt/mdata-client

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	joyent
GH_TAGNAME=	34c19b0
GH_PROJECT=	freebsd-kvm-image-builder

WRKSRC_SUBDIR=	triton-freebsd-guesttools
SHEBANG_FILES=	${WRKSRC}/lib/smartdc/add-network-interface \
		${WRKSRC}/lib/smartdc/common.lib \
		${WRKSRC}/lib/smartdc/firstboot \
		${WRKSRC}/lib/smartdc/format-secondary-disk \
		${WRKSRC}/lib/smartdc/get-user-data \
		${WRKSRC}/lib/smartdc/run-operator-script \
		${WRKSRC}/lib/smartdc/run-user-script \
		${WRKSRC}/lib/smartdc/set-hostname \
		${WRKSRC}/lib/smartdc/set-root-authorized-keys \
		${WRKSRC}/lib/smartdc/set-rootpassword \
		${WRKSRC}/lib/smartdc/triton

post-extract:
	@${RM} -r ${WRKSRC}/usr

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/etc/rc.d/triton

do-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/etc/rc.d/triton ${WRKSRC}/lib/smartdc/*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rc.d/triton ${STAGEDIR}${PREFIX}/etc/rc.d
	( cd ${WRKSRC}/lib/ && \
		${COPYTREE_BIN} smartdc ${STAGEDIR}${PREFIX}/lib )

.include <bsd.port.mk>
