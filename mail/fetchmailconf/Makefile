# $FreeBSD$

PORTNAME=	fetchmailconf
DISTNAME=	fetchmail-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
# NOTE: MASTER_SITES in ../fetchmail must NOT use the $PORTNAME variable,
# else _this_ port (fetchmailconf) becomes unfetchable

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Python-based GUI to configure fetchmail

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

# minimum required version 6.4.2 - not codified, on the assumption
# that fetchmail port updated at the same time
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		fetchmail>=${PORTVERSION}:mail/fetchmail
RUN_DEPENDS+=	${BUILD_DEPENDS}

USES=		python shebangfix tar:xz
USE_PYTHON=	py3kplist

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${FILESDIR}

SUB_FILES=	fetchmailconf
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
PLIST=		${.CURDIR}/pkg-plist
NO_ARCH=	yes

GNU_CONFIGURE=	yes

ALL_TARGET=	fetchmailconf
INSTALL_TARGET=	install-data-am install-nodist_binSCRIPTS install-man

post-install:
# first, run smoke tests - the version check makes sure we have all
# modules listed in the *_DEPENDS variables:
		${PYTHON_CMD} ${WRKSRC}/fetchmailconf.py -V
# then install:
		${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
		${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmail.1*

MASTERDIR=	${.CURDIR}/../fetchmail

.include "${MASTERDIR}/Makefile"
