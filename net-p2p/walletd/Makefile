PORTNAME=       walletd
DISTVERSIONPREFIX=	v
DISTVERSION=    0.1.1-alpha

CATEGORIES=     net-p2p

MAINTAINER=     bruno@tinkerbox.org
COMMENT=        Official Sia Wallet
WWW=            https://sia.tech/software/walletd

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           go:modules
USE_RC_SUBR=	walletd

GO_MODULE=      go.sia.tech/walletd
GO_TARGET=      ./cmd/walletd
GO_BUILDFLAGS+= -tags='netgo timetzdata' -trimpath

PLIST_FILES=	bin/walletd \
                "@sample(${USERS},${GROUPS},600) ${PREFIX}/etc/walletd.conf.sample" \
                "@sample ${PREFIX}/etc/newsyslog.conf.d/walletd.conf.sample" \
                "@dir(${USERS},${GROUPS},750) /var/lib/${PORTNAME}"

SUB_FILES=	${PORTNAME}-syslog.conf ${PORTNAME}.conf

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS} \
		PREFIX=${PREFIX}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-syslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL} -d ${STAGEDIR}/var/lib/${PORTNAME}


.include <bsd.port.mk>
