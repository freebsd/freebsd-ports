# $FreeBSD$

PORTNAME?=	husky
PORTVERSION=	1.9.20191207
PORTEPOCH?=	0
CATEGORIES?=	news mail
MASTER_SITES=	http://download.huskyproject.org/sources/
DISTNAME=	husky-all-1.9-source-20191207

MAINTAINER?=	osharoiko@gmail.com
COMMENT?=	Husky full featured highly portable FTN Tosser

.if ${PORTNAME} == "husky"
RUN_DEPENDS=	hpt:news/husky-hpt \
		htick:news/husky-htick

NO_BUILD=	yes
NO_INSTALL=	yes
.endif

USES+=		alias dos2unix gmake zip

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/${COMPONENT_SUBDIR}
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PKGDIR=		${.CURDIR}

USERS=		fido
GROUPS=		fido

pre-build:
	${LN} -sf ${WRKSRC}/huskybse/huskymak.cfg ${WRKSRC}
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|g++|${CXX}|' \
		${WRKSRC}/huskybse/huskymak.cfg

.include <bsd.port.mk>
