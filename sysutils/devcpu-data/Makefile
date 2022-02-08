# Created by: stas

PORTNAME=	data
PORTVERSION=	20220208
CATEGORIES=	sysutils
MASTER_SITES=	# none
PKGNAMEPREFIX=	devcpu-
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	AMD and Intel CPUs microcode updates

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USE_RC_SUBR=	microcode_update

DATADIR=	${PREFIX}/share/cpucontrol
NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
SUB_FILES=	pkg-message

NO_WRKSUBDIR=	yes

OPTIONS_DEFAULT=	AMD INTEL
OPTIONS_GROUP=		VENDOR
OPTIONS_GROUP_VENDOR=	AMD INTEL

AMD_DESC=	Depend on sysutils/devcpu-data-amd
INTEL_DESC=	Depend on sysutils/devcpu-data-intel

AMD_RUN_DEPENDS=	${LOCALBASE}/share/cpucontrol/microcode_amd.bin:sysutils/devcpu-data-amd
INTEL_RUN_DEPENDS=	/boot/firmware/intel-ucode.bin:sysutils/devcpu-data-intel

.include <bsd.port.mk>
