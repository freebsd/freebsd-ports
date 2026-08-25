PORTNAME=	sylve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/AlchemillaHQ/Sylve/releases/download/${DISTVERSIONFULL}/:web_assets
DISTFILES=	sylve-web-assets.tar.gz:web_assets

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Lightweight GUI for managing bhyve, jails, ZFS, and networking
WWW=		https://sylve.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_14=	requires OpenZFS 2.3.0 or newer and nlsysevent(4)
ONLY_FOR_ARCHS=	aarch64 amd64

RUN_DEPENDS=	dnsmasq>0:dns/dnsmasq \
		qemu-img:emulators/qemu@tools \
		swtpm>0:sysutils/swtpm \
		virsh:devel/libvirt

.include <bsd.port.options.mk>
.if ${ARCH} == amd64
RUN_DEPENDS+=	bhyve-firmware>0:sysutils/bhyve-firmware
.elif ${ARCH} == aarch64
RUN_DEPENDS+=	u-boot-bhyve-arm64>0:sysutils/u-boot-bhyve-arm64
.endif

USES=		go:modules samba:run
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/alchemillahq/sylve

GO_TARGET=	./cmd/sylve

SUB_FILES=	pkg-message

post-extract:
	@${RM} -r ${WRKSRC}/internal/assets/web-files
	@${MV} ${WRKDIR}/web-files ${WRKSRC}/internal/assets/

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/sylve
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.example.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
