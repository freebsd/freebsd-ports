PORTNAME=       hostd
DISTVERSIONPREFIX=	v
DISTVERSION=    1.1.2
CATEGORIES=     net-p2p

MAINTAINER=     bruno@tinkerbox.org
COMMENT=        Offer your storage space on the Sia network
WWW=            https://sia.tech/host

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           go:modules
USE_RC_SUBR=	hostd

GO_MODULE=      go.sia.tech/hostd
GO_TARGET=      ./cmd/hostd
GO_BUILDFLAGS+= -tags='netgo timetzdata' -trimpath

PLIST_FILES=	bin/hostd \
		"@sample ${PREFIX}/etc/hostd.yml.sample" \
		"@sample ${PREFIX}/etc/newsyslog.conf.d/hostd.conf.sample" \
		"@dir(${USERS},${GROUPS},750) /var/lib/${PORTNAME}"

SUB_FILES=	${PORTNAME}.yml ${PORTNAME}.conf

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.yml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yml.sample
	${INSTALL} -d ${STAGEDIR}/var/lib/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s|BUILDTIME|$$(date +%s)|g" ${WRKSRC}/build/meta.go

.include <bsd.port.mk>
