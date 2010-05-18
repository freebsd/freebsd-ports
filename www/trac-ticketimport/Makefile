# New ports collection makefile for: trac-ticketimport
# Date created:                      Dec 31, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:L}
PORTVERSION=	0.7c
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	brooks@freebsd.org
COMMENT=	Import or update tickets from a CSV file or Excel file

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0.7.1:${PORTSDIR}/textproc/py-xlrd
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	TicketImport

# Maintainter targets below this point

# Retrieve the latest version from SVN and package in a tarball.
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	    svn export http://trac-hacks.org/svn/ticketimportplugin/0.11/ \
	    ${DISTNAME}
	cd ${WRKDIR} && tar cvf ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

# Create a pkg-plist after the package is installed.
EGGDIR=		${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PLIST_EGGDIR=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
build-plist:
	${FIND} ${EGGDIR} -type f | \
	    ${SED} -e 's|${EGGDIR}|${PLIST_EGGDIR}|' | \
	    ${SORT} > pkg-plist
	${FIND} ${EGGDIR} -type d | \
	    ${SED} -e 's|${EGGDIR}|@dirrm ${PLIST_EGGDIR}|' | \
	    ${SORT} -r >> pkg-plist

.include <bsd.port.mk>
