# $FreeBSD$

PORTNAME=	vchanger
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	freebsd@netfence.it
COMMENT=	Disk-based virtual autochanger for Bacula

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		shebangfix
SHEBANG_FILES=	scripts/vchanger-genudevrules \
		scripts/vchanger-umount-uuid.sh \
		scripts/vchanger-mount-uuid.sh
GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
