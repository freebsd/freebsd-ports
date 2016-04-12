# Created by: Randy Westlund <rwestlun@gmail.com>
# $FreeBSD$

PORTNAME=	goobook
PORTVERSION=	1.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Search your Google contacts from the command-line or Mutt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauth2client>=1.4.12:security/py-oauth2client \
		${PYTHON_PKGNAMEPREFIX}gdata>=2.0.18:devel/py-gdata \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.1.0:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.1:www/py-httplib2

NO_ARCH=	yes
USES=		python:-2.7
USE_PYTHON=	autoplist distutils
PLIST_FILES=	man/man1/goobook.1.gz

post-stage:
	${INSTALL_DATA} ${WRKSRC}/goobook.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
