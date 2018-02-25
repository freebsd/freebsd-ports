# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	mailpile
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	mail security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Locally hosted web-browser based mail client

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/AGPLv3.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pgpdump>=0:security/py-pgpdump@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dns>=0:dns/py-dns@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spambayes>=0:mail/py-spambayes@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	mailpile
GH_PROJECT=	Mailpile

USES=		gettext python:2.7 shebangfix
python_OLD_CMD=	/usr/bin/python2
SHEBANG_FILES=	mailpile/contrib/gui/gui-o-matic.py \
		mailpile/contrib/gui/gui-test.sh \
		mailpile/contrib/gui/icons-osx/mk_icons.sh
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/bin/bash,#!/bin/sh,g' ${WRKSRC}/scripts/*.sh

.include <bsd.port.mk>
