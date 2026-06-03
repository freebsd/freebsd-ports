PORTNAME=	ucored
PORTVERSION=	v0.1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Utility to apply more extensive policies to user cores
WWW=		https://git.kevans.dev/kevans/ucored

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:54,build uidfix

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1500055
USES+=		kmod
PLIST_SUB+=	KMOD=
.else
PLIST_SUB+=	KMOD="@comment "
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/ucored.conf \
	    ${STAGEDIR}${PREFIX}/etc/ucored.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/devd/ucored.conf \
	    ${STAGEDIR}${PREFIX}/etc/devd/ucored.conf.sample

.include <bsd.port.mk>
