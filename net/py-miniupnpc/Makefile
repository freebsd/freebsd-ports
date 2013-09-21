# $FreeBSD$

CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for miniupnpc

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/miniupnpc:build

MASTERDIR=	${.CURDIR}/../miniupnpc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

WRKDIR=		${WRKDIRPREFIX}${MASTERDIR}/work
PLIST=		${.CURDIR}/pkg-plist

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

post-patch:
	@${REINPLACE_CMD} 's/\(version\)="[^"]*"/\1="${PORTVERSION}"/' \
		${WRKSRC}/setup.py

.include "${MASTERDIR}/Makefile"
