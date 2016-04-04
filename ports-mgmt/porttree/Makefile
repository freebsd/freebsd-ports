# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	porttree
PORTVERSION=	0.3.r${SVN_REV}
CATEGORIES=	ports-mgmt python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Show dependences of FreeBSD port as pseudo graphical tree

LICENSE=	MIT

USES=		python tar:bzip2

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}networkx>=1.5:math/py-networkx

.if target(gen-dist)
FETCH_DEPENDS+=	svn:devel/subversion
.endif

SVNROOT?=	http://porttree.googlecode.com/svn/trunk/
SVN_REV=	52
NO_BUILD=	yes
NO_INSTALL=	yes
PLIST_FILES=	bin/porttree man/man1/porttree.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/porttree.py ${STAGEDIR}${PREFIX}/bin/porttree
	${INSTALL_MAN} ${WRKSRC}/src/porttree.1 ${STAGEDIR}${MANPREFIX}/man/man1

gen-dist:
	${MKDIR} ${WRKDIR}
	${RM} -rf ${WRKSRC}
	svn export -r ${SVN_REV} ${SVNROOT} ${WRKSRC}
	${TAR} -cvy -C ${WRKDIR} --exclude FreeBSDport -f ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}

.include <bsd.port.mk>
