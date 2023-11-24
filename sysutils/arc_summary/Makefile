PORTNAME=	arc_summary
PORTVERSION=	20231023
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/openzfs/zfs/${_REV}/cmd/
DISTFILES=	${PORTNAME}?${PORTVERSION}

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

_REV=		e57909265b4352832d69f5107bac7e56d6a8fbd2

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
