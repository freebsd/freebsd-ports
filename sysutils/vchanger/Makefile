PORTNAME=	vchanger
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ml@netfence.it
COMMENT=	Disk-based virtual autochanger for Bacula
WWW=		https://vchanger.sourceforge.io

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		shebangfix
SHEBANG_FILES=	scripts/vchanger-genudevrules \
		scripts/vchanger-umount-uuid.sh \
		scripts/vchanger-mount-uuid.sh
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
OPTIONS_DEFINE=	DOCS
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
