PORTNAME=	arc_summary
PORTVERSION=	20231114
CATEGORIES=	sysutils
MASTER_SITES=	https://cgit.freebsd.org/src/plain/sys/contrib/openzfs/cmd/ \
		https://cgit.freebsd.org/src/plain/sys/contrib/openzfs/cmd/arc_summary/:13
DISTFILES=	${PORTNAME}3?h=releng/13.2:13 \
		${PORTNAME}?h=releng/14.0 \
		${PORTNAME}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Print ZFS ARC cache statistics and other information
WWW=		https://cuddletech.com/2008/10/explore-your-zfs-adaptive-replacement-cache-arc/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/arc_summary

.include <bsd.port.pre.mk>

do-extract:
.if ${OSVERSION} < 1400000
	${CP} ${DISTDIR}/${PORTNAME}3?h=releng/13.2 ${WRKSRC}/${PORTNAME}
.elif ${OSVERSION} >= 1400000 && ${OSVERSION} < 1500000
	${CP} ${DISTDIR}/${PORTNAME}?h=releng/14.0 ${WRKSRC}/${PORTNAME}
.else
	${CP} ${DISTDIR}/${PORTNAME} ${WRKSRC}/${PORTNAME}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
