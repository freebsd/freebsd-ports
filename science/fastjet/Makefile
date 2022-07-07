PORTNAME=	fastjet
DISTVERSION=	3.4.0
CATEGORIES=	science
MASTER_SITES=	https://fastjet.fr/repo/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for jet finding in pp and e+e- collisions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		fortran gmake libtool shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	fastjet-config.in

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-allplugins

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=			CGAL PYTHON
OPTIONS_DEFAULT=		PYTHON
OPTIONS_SUB=			yes

CGAL_DESC=			Build with CGAL computational geometry library
CGAL_CONFIGURE_ENABLE=		cgal-header-only
CGAL_BUILD_DEPENDS=		cgal>0:math/cgal
CGAL_BROKEN=			cgal-header-only doesn't seem to do anything, upstream was notified via bug reporting e-mail address on 2022-07-08

PYTHON_USES=			python
PYTHON_CONFIGURE_ENABLE=	pyext swig
PYTHON_CONFIGURE_ENV=		PYTHON_CONFIG=${PYTHON_CMD}-config
PYTHON_BUILD_DEPENDS=		swig:devel/swig

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_fastjet.so.0.0.0

.include <bsd.port.mk>
