# New ports collection makefile for:	porttree
# Date created:			18 Aug 2011
# Whom:				Vladimir Chukharev
#
# $FreeBSD$
#

PORTNAME=	porttree
PORTVERSION=	0.2.r${SVN_REV}
CATEGORIES=	ports-mgmt python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Show dependences of FreeBSD port as pseudo graphical tree

LICENSE=	MIT

MAN1=		porttree.1
USE_BZIP2=	yes
USE_PYTHON=	2.4+

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}networkx>=1.5:${PORTSDIR}/math/py-networkx

.if target(gen-dist)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

SVNROOT?=	http://porttree.googlecode.com/svn/trunk/
SVN_REV=	20
NO_BUILD=	yes
NO_INSTALL=	yes
PLIST_FILES=	bin/porttree

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/porttree.py ${PREFIX}/bin/porttree
	${INSTALL_MAN} ${WRKSRC}/src/porttree.1 ${MAN8PREFIX}/man/man1

gen-dist:
	${MKDIR} ${WRKDIR}
	${RM} -rf ${WRKSRC}
	svn export -r ${SVN_REV} ${SVNROOT} ${WRKSRC}
	${TAR} -cvy -C ${WRKDIR} --exclude FreeBSDport -f ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}

.include <bsd.port.mk>
