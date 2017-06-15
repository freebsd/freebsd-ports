# $FreeBSD$

PORTNAME?=	husky
PORTVERSION=	1.9.20140519
PORTREVISION?=	2
PORTEPOCH?=	0
CATEGORIES?=	news mail
MASTER_SITES=	SF/husky/husky/1.9-current/2014.05.19

MAINTAINER?=	osharoiko@gmail.com
COMMENT?=	Husky full featured highly portable FTN Tosser

DISTNAME=	husky-all-1.9-source-20140519

.if ${PORTNAME} == "husky"
RUN_DEPENDS=	hpt:news/husky-hpt \
		htick:news/husky-htick

NO_BUILD=	yes
NO_INSTALL=	yes
.endif

USES+=		alias gmake tar:tgz

HUSKY_ROOTDIR=	${WRKDIR}/husky
PATCH_WRKSRC=	${HUSKY_ROOTDIR}
WRKSRC=		${HUSKY_ROOTDIR}/${COMPONENT_SUBDIR}
PKGDIR=		${.CURDIR}

USERS=		fido
GROUPS=		fido

pre-build:
	${LN} -sf ${HUSKY_ROOTDIR}/huskybse/huskymak.cfg ${HUSKY_ROOTDIR}
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|g++|${CXX}|' \
		${HUSKY_ROOTDIR}/huskybse/huskymak.cfg

.include <bsd.port.mk>
