PORTNAME=	fstyp
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} http://thegaul.org/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Detect which filesystem type a device/partition contains

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_prog_CC="${CC}"

PLIST_FILES=	bin/fstyp man/man8/fstyp.8.gz

.include <bsd.port.mk>
