# $FreeBSD$

PORTNAME=	fetchmailconf
DISTNAME=	fetchmail-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Python-based GUI to configure fetchmail

BROKEN=		unfetchable

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		fetchmail>=${PORTVERSION}:mail/fetchmail

USES=		python:2.7 shebangfix tar:xz

FILESDIR=	${.CURDIR}/files

SUB_FILES=	fetchmailconf
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
PLIST=		${.CURDIR}/pkg-plist
NO_ARCH=	yes

GNU_CONFIGURE=	yes

TARGET=		fetchmailconf
INSTALL_TARGET=	install-data-am install-nodist_binSCRIPTS install-man

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
	${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmail.1*

MASTERDIR=	${.CURDIR}/../fetchmail

.include "${MASTERDIR}/Makefile"
