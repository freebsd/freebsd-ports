# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	porttree
PORTVERSION=	0.3.r${SVN_REV}
PORTREVISION=	1
CATEGORIES=	ports-mgmt python
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Show dependences of FreeBSD port as pseudo graphical tree

LICENSE=	MIT

USES=		python:2.7 tar:bzip2 shebangfix

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}networkx>=1.5:math/py-networkx@${PY_FLAVOR}

.if target(gen-dist)
FETCH_DEPENDS+=	svn:devel/subversion
.endif

SVNROOT?=	http://porttree.googlecode.com/svn/trunk/
SVN_REV=	52
NO_BUILD=	yes
PLIST_FILES=	bin/porttree man/man1/porttree.1.gz
NO_ARCH=	yes

SHEBANG_FILES=	src/porttree.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/porttree.py ${STAGEDIR}${PREFIX}/bin/porttree
	${INSTALL_MAN} ${WRKSRC}/src/porttree.1 ${STAGEDIR}${MANPREFIX}/man/man1

gen-dist:
	${MKDIR} ${WRKDIR}
	${RM} -r ${WRKSRC}
	svn export -r ${SVN_REV} ${SVNROOT} ${WRKSRC}
	${TAR} -cvy -C ${WRKDIR} --exclude FreeBSDport -f ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}

.include <bsd.port.mk>
