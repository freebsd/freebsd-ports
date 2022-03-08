PORTNAME=	wifibox
PORTVERSION=	0.8.0
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Wireless card driver via virtualized Linux

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
EXTRACT_ONLY=	${_DISTFILES:N*.img.xz}

RUN_DEPENDS=	grub2-bhyve>0:sysutils/grub2-bhyve

OPTIONS_DEFINE=			BHYVE_PLUS WPA_PASSTHRU
OPTIONS_DEFAULT=		WPA_PASSTHRU
OPTIONS_EXCLUDE_FreeBSD_12=	BHYVE_PLUS

BHYVE_PLUS_DESC=		Use bhyve+ (experimental)
WPA_PASSTHRU_DESC=		Support WPA Supplicant pass-through

WPA_PASSTHRU_RUN_DEPENDS=	socat>0:net/socat

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBHYVE_PLUS} || (${OSVERSION} < 1300000)
RUN_DEPENDS+=	bhyve+>0:sysutils/bhyve+
_BHYVE_PLUS=	yes
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	pgj
GH_PROJECT=	freebsd-wifibox freebsd-wifibox-image:image
GH_TAGNAME=	${PORTVERSION}
GH_TAGNAME+=	${IMAGE_VERSION}:image

IMAGE_VERSION=	snapshot-20220307
IMAGE_FILE=	freebsd-wifibox-appliance.${IMAGE_VERSION}.img.xz
IMAGE_MAN=	wifibox-alpine.5

MASTER_SITES+=	https://github.com/pgj/freebsd-wifibox-image/releases/download/${IMAGE_VERSION}/
DISTFILES+=	${IMAGE_FILE}

# Needed to fake the necessary UID/GID for chrony that runs in the guest
USERS=		squid quagga
GROUPS=		squid quagga

NO_BUILD=	yes
MAKE_ENV+=	IMGXZ=${DISTDIR}/${IMAGE_FILE} \
		IMGMAN=${WRKSRC_image}/man/${IMAGE_MAN} \
		VERSION=${PORTVERSION}
.if defined(_BHYVE_PLUS)
MAKE_ENV+=	BHYVE=${LOCALBASE}/sbin/bhyve \
		BHYVECTL=${LOCALBASE}/sbin/bhyvectl \
		VMM_KO=${KMODDIR}/vmm.ko
.endif

.include <bsd.port.mk>
