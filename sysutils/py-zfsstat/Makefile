PORTNAME=	zfsstat
PORTVERSION=	2.4.4
CATEGORIES=	sysutils python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	OpenZFS Python stat utilities
WWW=		https://github.com/openzfs/zfs/tree/zfs-${PORTVERSION}/cmd

LICENSE=	CDDL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sysctl>=0:devel/py-sysctl@${PY_FLAVOR}

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src
SRC=		${.CURDIR}/src
USES=		python shebangfix

SRC_FILES=	dbufstat.in zarcstat.in zarcsummary zilstat.in

# All script and man files are taken directly from OpenZFS source

SCRIPT_FILES=	bin/dbufstat \
		bin/zarcstat \
		bin/zarcsummary \
		bin/zilstat

MAN_FILES=	share/man/man1/dbufstat.1.gz \
		share/man/man1/zarcstat.1.gz \
		share/man/man1/zarcsummary.1.gz \
		share/man/man1/zilstat.1.gz

PLIST_FILES=	${SCRIPT_FILES} ${MAN_FILES}

do-extract:
	${MKDIR} ${WRKSRC}
.for f in ${SRC_FILES}
	${SED} -e "1s|^.*$$|\#!${PYTHON_CMD}|" \
		${SRC}/${f} > ${WRKSRC}/${f:C/.in$$//}
.endfor
	@${CP} -R ${SRC}/*.1 ${WRKSRC}

do-install:
.for f in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f:C/^bin.//} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for f in ${SRC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${f:C/.in$$//}.1 ${STAGEDIR}${MANDIRS}/man1/
.endfor

.include <bsd.port.mk>
