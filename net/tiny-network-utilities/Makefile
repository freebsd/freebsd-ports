PORTNAME=	tiny-network-utilities
PORTVERSION=	1.0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimalistic DHCP, UDP proxy, etc server implementations

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hexdump>0:textproc/py-hexdump@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
SHEBANG_FILES=	*.py
NO_BUILD=	yes
NO_ARCH=	yes

FILES_EXEC=	tiny-dhcp-server tiny-udp-proxy tiny-udp-anti-nat
FILES_LIB=	net_checksums tiny_utils
PLIST_FILES=	${FILES_EXEC:%=bin/%} ${FILES_LIB:%=${PYTHON_SITELIBDIR}/%.py}

do-install:
.for file_exec in ${FILES_EXEC}
	${INSTALL_SCRIPT} ${WRKSRC}/${file_exec}.py \
		${STAGEDIR}${PREFIX}/bin/${file_exec}
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
.for file_lib in ${FILES_LIB}
	${INSTALL_DATA} ${WRKSRC}/${file_lib}.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${file_lib}.py
.endfor

.include <bsd.port.mk>
