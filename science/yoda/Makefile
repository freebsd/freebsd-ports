# $FreeBSD$

PORTNAME=	yoda
DISTVERSION=	1.7.3
CATEGORIES=	science
MASTER_SITES=	http://www.hepforge.org/archive/${PORTNAME}/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Particle physics package with classes for data analysis, histogramming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=			python shebangfix
PYTHON_USE=			PYTHON=cython
PYTHON_CONFIGURE_ENABLE=	pyext
PYTHON_MAKE_ENV=		PYTHON_VERSION=${PYTHON_VER} PYTHON=${PYTHON_CMD}
PYTHON_VARS=			SHEBANG_FILES="bin/${PORTNAME}* bin/aida2yoda bin/aida2flat bin/flat2yoda"
PYTHON_BROKEN=			Fails with "Error: 'lib/python2.7/site-packages/yoda/plotting.pyc' is referring to /usr/ports/science/yoda/work/stage"

post-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	@${MV} ${STAGEDIR}${PREFIX}/share/${PORTNAME:tu}/yoda-completion ${STAGEDIR}${PREFIX}/share/bash-completion/completions/

post-install-PYTHON-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/${PORTNAME:tu}

.include <bsd.port.mk>
