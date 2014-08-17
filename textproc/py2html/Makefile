# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	py2html
PORTVERSION=	0.7
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	-${PYTHON_PKGNAMEPREFIX:S/-//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Highlighter for HTML

USES=			shebangfix
USE_PYTHON=		2
USE_PYDISTUTILS=	yes

python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
SHEBANG_FILES=	py2html

.include <bsd.port.mk>
