PORTNAME=	arc_summary
PORTVERSION=	20220410
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

_REV=		0a9aaa7f0cc16f1771f492cce665bc5c5eb8e735

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
