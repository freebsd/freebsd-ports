# $FreeBSD$

PORTNAME=	fetchmailconf
PORTREVISION=	0
DISTNAME=	fetchmail-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Python-based GUI to configure fetchmail

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		fetchmail>=${PORTVERSION}:mail/fetchmail

USES=		python shebangfix tar:xz

FILESDIR=	${.CURDIR}/files

SHEBANG_FILES=	fetchmailconf.py
SUB_FILES=	fetchmailconf
PLIST=		${.CURDIR}/pkg-plist
NO_ARCH=	yes

GNU_CONFIGURE=	yes

TARGET=		fetchmailconf
INSTALL_TARGET=	install-data-am install-nodist_binSCRIPTS install-man

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fetchmailconf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/fetchmailconf.py ${STAGEDIR}${PREFIX}/libexec
	${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmail.1*

MASTERDIR=	${.CURDIR}/../fetchmail

.include "${MASTERDIR}/Makefile"
