# $FreeBSD$

PORTNAME=	mrtparse
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MRT format data parser

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix

GH_ACCOUNT=	t2mune
GH_PROJECT=	${PORTNAME}

NO_ARCH=	yes
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	examples/mrt2bgpdump.py \
		examples/mrt2exabgp.py

post-patch:
	@${MV} ${WRKSRC}/examples/mrt2bgpdump.py ${WRKSRC}/examples/mrt2bgpdump
	@${MV} ${WRKSRC}/examples/mrt2exabgp.py ${WRKSRC}/examples/mrt2exabgp
	@${RM} ${WRKSRC}/examples/README.rst

.include <bsd.port.mk>
