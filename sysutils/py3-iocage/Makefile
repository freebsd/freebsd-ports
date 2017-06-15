# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	0.9.7
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_PACKAGE=	should be compiled using python ${PYTHON_VER} or greater

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py3-click \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py3-tqdm \
		ca_root_nss>0:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.7:textproc/py3-texttable \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py3-requests

USE_GITHUB=	yes

NO_ARCH=	yes
USES=		python:3.6
USE_PYTHON=	autoplist distutils

CONFLICTS=	py-iocage-[0-9]* iocage-[0-9]* iocage-devel-[0-9]*

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "##################################################"
	@${ECHO_MSG} " The new iocage needs python ${PYTHON_VER} or greater."
	@${ECHO_MSG} ""
	@${ECHO_MSG} " If you want use the new iocage, stop the build now and"
	@${ECHO_MSG} " add this line to your /etc/make.conf, and then restart the build."
	@${ECHO_MSG} ""
	@${ECHO_MSG} " DEFAULT_VERSIONS+=python3=${PYTHON_VER}"
	@${ECHO_MSG} "##################################################"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
