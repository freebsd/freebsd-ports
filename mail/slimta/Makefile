PORTNAME=	slimta
PORTVERSION=	0.7.9
CATEGORIES=	mail
MASTER_SITES=	CHEESESHOP

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Configurable MTA based on the python-slimta libraries

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slimta>0:mail/py-python-slimta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	${PORTNAME}
REINPLACE_ARGS=	-i ''
NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES=	"@sample etc/slimta/logging.yaml.sample" \
		"@sample etc/slimta/slimta.yaml.sample"

post-patch:
.for file in setup main state
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${PORTNAME}/app/${file}.py
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
.for file in logging ${PORTNAME}
	@${CP} ${WRKSRC}/${PORTNAME}/app/etc/${file}.yaml.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
.endfor

.include <bsd.port.mk>
