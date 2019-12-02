# $FreeBSD$

PORTNAME=	mrtparse
PORTVERSION=	1.7
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

SHEBANG_FILES=	examples/print_all.py \
		examples/mrt2bgpdump.py \
		examples/mrt2exabgp.py \
		examples/slice.py \
		examples/summary.py

post-patch:
	@${MV} ${WRKSRC}/examples/print_all.py ${WRKSRC}/examples/mrt_print_all
	@${MV} ${WRKSRC}/examples/mrt2bgpdump.py ${WRKSRC}/examples/mrt2bgpdump
	@${MV} ${WRKSRC}/examples/mrt2exabgp.py ${WRKSRC}/examples/mrt2exabgp
	@${MV} ${WRKSRC}/examples/slice.py ${WRKSRC}/examples/mrt_slice
	@${MV} ${WRKSRC}/examples/summary.py ${WRKSRC}/examples/mrt_summary
	@${RM} ${WRKSRC}/examples/README.rst

.include <bsd.port.mk>
