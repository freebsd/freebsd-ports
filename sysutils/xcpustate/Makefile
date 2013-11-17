# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	xcpustate
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.cs.toronto.edu/pub/jdd/xcpustate/
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitoring utility graphically showing cpu load and status

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	# none

NO_WRKSUBDIR=	yes

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xt

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
