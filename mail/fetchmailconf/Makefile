PORTNAME=	fetchmailconf
PORTREVISION=	0
DISTNAME=	fetchmail-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
# NOTE: MASTER_SITES in ../fetchmail must NOT use the $PORTNAME variable,
# else _this_ port (fetchmailconf) becomes unfetchable

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Python-based GUI to configure fetchmail

LICENSE=	GPLv2+

# minimum required version 6.4.2 - not codified, on the assumption
# that fetchmail port updated at the same time
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		fetchmail>=${PORTVERSION}:mail/fetchmail
BUILD_DEPENDS+=	${RUN_DEPENDS}

USES=		python shebangfix tar:xz
USE_PYTHON=	py3kplist

GNU_CONFIGURE=	yes
ALL_TARGET=	fetchmailconf
INSTALL_TARGET=	install-data-am install-nodist_binSCRIPTS install-man

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${FILESDIR}
NO_ARCH=	yes

SUB_FILES=	fetchmailconf
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
PLIST=		${.CURDIR}/pkg-plist

post-install:
# first, run smoke tests - the version check makes sure we have all
# modules listed in the *_DEPENDS variables:
		${PYTHON_CMD} ${WRKSRC}/fetchmailconf.py -V
# then install:
		${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
		${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmail.1*

MASTERDIR=	${.CURDIR}/../fetchmail

.include "${MASTERDIR}/Makefile"
