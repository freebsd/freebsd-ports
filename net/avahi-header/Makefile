PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-header

COMMENT=	Install an avahi-gtk* header to avoid conflict

CONFLICTS=	avahi-gtk-0.7.[0-2]*

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	header

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/include/avahi-ui
	${INSTALL_DATA} ${BUILD_WRKSRC}/avahi-ui.h \
		${STAGEDIR}/${PREFIX}/include/avahi-ui/

.include "${MASTERDIR}/Makefile"
