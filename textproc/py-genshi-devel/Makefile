# New ports collection makefile for:	py-genshi-devel
# Date created:				Wed 06 May 2009
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$
#

PORTNAME=	Genshi
PORTVERSION=	0.6.1052
PORTREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Python toolkit for stream-based generation of output for the web

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

WRKSRC=		${WRKDIR}/genshi
CONFLICTS=	py-genshi-[0-9]*

PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}dev
PYDISTUTILS_INSTALLARGS=	-Z -O 1 -N \
				-S ${PYTHONPREFIX_SITELIBDIR}/site-packages \
				-d ${PYTHONPREFIX_SITELIBDIR} \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,@dirrm share/man(/.*)?$$,,g \
		;s,${PYTHON_SITELIBDIR:S,^${PYTHONBASE}/,,},%%PYTHON_SITELIBDIR%%,g \
		;s,^${DOCSDIR_REL},%%PORTDOCS%%%%DOCSDIR%%,g \
		;s,@dirrm ${DOCSDIR_REL},%%PORTDOCS%%@dirrm %%DOCSDIR%%,g \
		;s,^${EXAMPLESDIR_REL},%%PORTEXAMPLES%%%%EXAMPLESDIR%%,g \
		;s,@dirrm ${EXAMPLESDIR_REL},%%PORTEXAMPLES%%@dirrm %%EXAMPLESDIR%%,g \
		;s,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
