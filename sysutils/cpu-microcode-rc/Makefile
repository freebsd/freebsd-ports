PORTNAME=	microcode
PORTVERSION=	1.0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	cpu-
PKGNAMESUFFIX=	-rc
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	RC script for CPU microcode updates

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386

USE_RC_SUBR=	microcode_update

DATADIR=	${PREFIX}/share/cpucontrol
NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
SUB_FILES=	pkg-message

NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
