# Created by: Alexander Novitsky
# $FreeBSD$

PORTNAME=	smbpasswd
PORTVERSION=	1.0.2
CATEGORIES=	net python
MASTER_SITES=	http://barryp.org/static/media/software/download/py-${PORTNAME}/${PORTVERSION}/ \
		GOOGLE_CODE \
		CHEESESHOP
PROJECTHOST=	py-smbpasswd
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	SMB/CIFS password generation utility for Python

LICENSE=	GPLv2

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/smbpasswd.so
# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
