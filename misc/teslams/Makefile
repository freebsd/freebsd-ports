# Created by: Bruce A. Mah <bmah@freebsd.org>
# $FreeBSD$

PORTNAME=	teslams
PORTVERSION=	1.1.4
CATEGORIES=	misc

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Node.js implementation of Tesla Model S API client

# teslams is BSD2CLAUSE but the installation pulls in a bunch
# of other packages with varying licenses.
LICENSE=	BSD2CLAUSE BSD3CLAUSE APACHE20 MIT ISCL
LICENSE_COMB=	multi

BROKEN=		tries to download from registry.npmjs.org during stage phase

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm

NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	hjespers
GH_PROJECT=	teslams
GH_TAGNAME=	6f6dfa2

SCRIPTS=	chargebar climatemon restla streaming teslacmd teslamap \
		visualize/visualize

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib ; ${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})
	# Link to executable scripts where the user can run them
.for l in ${SCRIPTS}
	${LN} -s ../lib/node_modules/${PORTNAME}/examples/${l}.js ${STAGEDIR}${PREFIX}/bin/`echo ${l} | ${SED} -e 's,.*/,,'`
.endfor

	# We have to generate the plist dynamically here because the
	# npm install process pulls in dependencies at port install
	# time, therefore the exact set of files included in the port
	# isn't known until we try to install it.  Another implication
	# is that a rebuild of the port may wind up with different versions
	# of dependencies but still carry the same version number.  :-(
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s bin -not -type d) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s lib/node_modules/${PORTNAME} -not -type d) >> ${TMPPLIST}

.include <bsd.port.mk>
