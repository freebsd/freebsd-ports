# vim:ts=8 sw=8 noet
# Ports collection Makefile for:	py-pandas
# Date created:				2012-08-16
# Whom:					John W. O'Brien
#
# $FreeBSD$
#

PORTNAME=	pandas
DISTVERSION=	0.8.1
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Flexible, high-performance data analysis in Python

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
