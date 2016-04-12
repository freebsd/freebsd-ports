# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	mailpile
PORTVERSION=	0.5.2
CATEGORIES=	mail security

MAINTAINER=	yuri@rawbw.com
COMMENT=	Locally hosted web-browser based mail client

LICENSE=	AGPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}pgpdump>=0:security/py-pgpdump \
		${PYTHON_PKGNAMEPREFIX}dns>=0:dns/py-dns \
		${PYTHON_PKGNAMEPREFIX}spambayes>=0:mail/py-spambayes

USE_GITHUB=	yes
GH_ACCOUNT=	mailpile
GH_PROJECT=	Mailpile

USES=		gettext python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^#!/bin/bash,#!/bin/sh,g' ${WRKSRC}/scripts/*.sh

.include <bsd.port.mk>
