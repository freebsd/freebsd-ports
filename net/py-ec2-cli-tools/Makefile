PORTNAME=	ec2-cli-tools
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Helpful CLI utilities for querying and connecting to EC2 instances
WWW=		https://github.com/FlipPath/ec2-cli-tools

LICENSE=	MIT

DEPRECATED=	Depends on expired devel/py-boto
EXPIRATION_DATE=2025-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>=1.0:devel/py-boto@${PY_FLAVOR} \
		bash:shells/bash

USE_PYTHON=	distutils autoplist
USES=		python shebangfix
SHEBANG_FILES=	bin/ec2getsnaps bin/ec2hostcache bin/ec2ssh

.include <bsd.port.mk>
