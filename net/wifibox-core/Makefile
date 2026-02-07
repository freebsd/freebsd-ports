PORTNAME=	wifibox-core
PORTVERSION=	0.15.1
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Wifibox core functionality
WWW=		https://github.com/pgj/freebsd-wifibox

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	grub2-bhyve>0:sysutils/grub2-bhyve

OPTIONS_SINGLE=			RECOVERY
OPTIONS_SINGLE_RECOVERY=	RECOVER_RESTART_VMM \
				RECOVER_SUSPEND_GUEST \
				RECOVER_SUSPEND_VMM \
				RECOVER_NONE

OPTIONS_DEFAULT=		RECOVER_RESTART_VMM

RECOVER_RESTART_VMM_DESC=	Restart the guest and reload vmm(4) kernel module on resume
RECOVER_SUSPEND_GUEST_DESC=	Stop the guest on suspend, start on resume
RECOVER_SUSPEND_VMM_DESC=	Stop the guest and unload vmm(4) on suspend, start the guest and reload vmm(4) on resume
RECOVER_NONE_DESC=		No recovery for suspend/resume

.include <bsd.port.options.mk>

USE_GITHUB=	yes
GH_ACCOUNT=	pgj
GH_PROJECT=	freebsd-wifibox

NO_BUILD=	yes
MAKE_ARGS+=	GUEST_ROOT=${LOCALBASE}/share/wifibox \
		GUEST_MAN=${LOCALBASE}/share/man/man5/wifibox-alpine.5.gz \
		VERSION=${PORTVERSION} \
		RECOVERY_METHOD=${PORT_OPTIONS:MRECOVER_*:S/RECOVER_//:tl}

.if ${OSVERSION} > 1400089
MAKE_ARGS+=	DEVD_FIX=
PLIST_SUB+=	DEVD_FIX="@comment "
.else
PLIST_SUB+=	DEVD_FIX=""
.endif

.include <bsd.port.mk>
