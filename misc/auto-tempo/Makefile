PORTNAME=	auto-tempo
DISTVERSION=	g20250902
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	slw@zxy.spb.ru
COMMENT=	Manage Jira Tempo Timesheets worklogs from a text file
WWW=		https://github.com/atteo/Auto-Tempo

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		git:devel/git

USES=		python shebangfix
SHEBANG_FILES=	autotempo.py

USE_PYTHON=	flavors
USE_GITHUB=	yes

GH_ACCOUNT=	atteo
GH_PROJECT=	Auto-Tempo
GH_TAGNAME=	0eb4159

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/autotempo

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/autotempo.py \
			${STAGEDIR}${PREFIX}/bin/autotempo

.include <bsd.port.mk>
