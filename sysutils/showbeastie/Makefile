# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	showbeastie
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=
DISTFILES=

MAINTAINER=	t@tobik.me
COMMENT=	Preview FreeBSD loader logos

LICENSE=	BSD2CLAUSE

# Let's pretend we build a kernel module, because we require the
# kernel sources
USES=		kmod

NO_FETCH=	yes

ALL_TARGET=	testmain

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	@${MKDIR} ${WRKSRC}
	@(cd ${SRC_BASE}/sys/boot/ficl && ${COPYTREE_SHARE} . ${WRKSRC})

post-patch:
	${REINPLACE_CMD} 's|-I.*/\.\./common|-I${SRC_BASE}/sys/boot/common|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/testmain ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
