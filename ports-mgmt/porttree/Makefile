# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	porttree
PORTVERSION=	1.0.r${SVN_REV}
CATEGORIES=	ports-mgmt python
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Show dependences of FreeBSD port as pseudo graphical tree

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>0:devel/py-configargparse@${PY_FLAVOR}

USES=		python tar:bzip2 shebangfix

SVN_REV=	102
NO_BUILD=	yes
PLIST_FILES=	bin/porttree man/man1/porttree.1.gz
NO_ARCH=	yes

SHEBANG_FILES=	src/porttree.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/porttree.py ${STAGEDIR}${PREFIX}/bin/porttree
	${INSTALL_MAN} ${WRKSRC}/src/porttree.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-test:
	LC_ALL="en_US.UTF-8" ${WRKSRC}/tests/tests.sh

# maintainer section:
# require: devel/subversion
SVNROOT?=	https://svn.code.sf.net/p/porttree/code/trunk
gen-dist:
	${MKDIR} ${WRKDIR}
	${RM} -r ${WRKSRC}
	svn export -r ${SVN_REV} ${SVNROOT} ${WRKSRC}
	${TAR} -cvy -C ${WRKDIR} --exclude FreeBSDport -f ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}

.include <bsd.port.mk>
