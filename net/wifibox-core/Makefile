PORTNAME=	wifibox-core
PORTVERSION=	0.10.0
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Wifibox core functionality

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	grub2-bhyve>0:sysutils/grub2-bhyve

OPTIONS_DEFINE=			BHYVE_PLUS
OPTIONS_DEFAULT=		#
OPTIONS_EXCLUDE_FreeBSD_12=	BHYVE_PLUS

BHYVE_PLUS_DESC=		Use bhyve+ (experimental)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBHYVE_PLUS} || (${OSVERSION} < 1300000)
RUN_DEPENDS+=	bhyve+>0:sysutils/bhyve+
_BHYVE_PLUS=	yes
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	pgj
GH_PROJECT=	freebsd-wifibox

NO_BUILD=	yes
MAKE_ARGS+=	GUEST_ROOT=${LOCALBASE}/share/wifibox \
		GUEST_MAN=${LOCALBASE}/man/man5/wifibox-alpine.5.gz \
		VERSION=${PORTVERSION}
.if defined(_BHYVE_PLUS)
MAKE_ARGS+=	BHYVE=${LOCALBASE}/sbin/bhyve \
		BHYVECTL=${LOCALBASE}/sbin/bhyvectl \
		VMM_KO=${KMODDIR}/vmm.ko
.endif

.include <bsd.port.mk>
