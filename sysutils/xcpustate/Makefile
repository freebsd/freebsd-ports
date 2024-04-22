PORTNAME=	xcpustate
PORTVERSION=	2.9
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.cs.toronto.edu/pub/jdd/xcpustate/
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitoring utility graphically showing cpu load and status
WWW=		https://www.cs.toronto.edu/~jdd/

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	# none

NO_WRKSUBDIR=	yes

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xt

PLIST_FILES=	"@(,kmem,2555) bin/${PORTNAME}" share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} 's/InstKmemFlags/InstBinFlags/' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
