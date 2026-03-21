PORTNAME=	unicode-show
DISTVERSION=	48.8-1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Detect and annotate suspicious Unicode characters in text or files
WWW=		https://www.kicksecure.com/wiki/Unicode-show

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.12+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Kicksecure
GH_PROJECT=	helper-scripts

SHEBANG_FILES=	usr/bin/unicode-show

NO_ARCH=	yes

do-build:
.for m in unicode_show stdisplay
	@${RM} -r ${WRKSRC}/usr/lib/python3/dist-packages/${m}/tests
	@${RM} ${WRKSRC}/usr/lib/python3/dist-packages/${m}/py.typed
	@${PYTHON_CMD} -OO ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHON_SITELIBDIR} \
		-f ${WRKSRC}/usr/lib/python3/dist-packages/${m}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/unicode-show ${STAGEDIR}${PREFIX}/bin/unicode-show
.for m in unicode_show stdisplay
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${m}
	@cd ${WRKSRC}/usr/lib/python3/dist-packages/${m} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/${m}
.endfor
	${INSTALL_MAN} ${WRKSRC}/auto-generated-man-pages/unicode-show.1 ${STAGEDIR}${PREFIX}/share/man/man1/unicode-show.1

.include <bsd.port.mk>
