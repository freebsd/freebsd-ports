PORTNAME=	microcode
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
PKGNAMEPREFIX=	cpu-
PKGNAMESUFFIX=	-rc
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	jrm@FreeBSD.org
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
