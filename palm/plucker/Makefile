# New ports collection makefile for:    plucker
# Date created:         30th May 2001
# Whom:                 Jose Marques <noway@nohow.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	plucker
PORTVERSION=	1.8
CATEGORIES=	palm www
MASTER_SITES=	http://downloads.plkr.org/${PORTVERSION}/ \
		http://downloads.hideho.org/${PORTNAME}/${PORTVERSION}/
DISTFILES=	${PORTNAME}_viewer-${PORTVERSION}.tar.bz2 \
		${PORTNAME}_viewer_extras-${PORTVERSION}.tar.bz2 \
		${PORTNAME}_parser-${PORTVERSION}.tar.bz2 \
		${PORTNAME}_docs-${PORTVERSION}.tar.bz2

MAINTAINER=	mt@primats.org.ua
COMMENT=	An offline HTML viewer for PalmOS devices

BUILD_DEPENDS=	ppmtoTbmp:${PORTSDIR}/palm/ppmtoTbmp \
		convert:${PORTSDIR}/graphics/ImageMagick \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/bin/pilot-xfer:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_BZIP2=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAN1=		plucker-build.1 plucker-decode.1 plucker-dump.1
FIND?=		find
NO_BUILD=	yes

MYPORTDOCS=	AUTHORS BUGREPORT COPYING CREDITS ChangeLog FAQ NEWS README REQUIREMENTS

.include <bsd.port.pre.mk>

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/PyPlucker
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/PyPlucker

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/PyPlucker/helper
	cd ${WRKSRC}; ${FIND} PyPlucker \
		\( -name "*.py" -or -name "*.py?" \) \
		-exec ${INSTALL_DATA} {} ${PYTHON_SITELIBDIR}/{} \;
.for F in Spider.py PluckerDocs.py Decode.py
	${INSTALL_SCRIPT} ${WRKSRC}/PyPlucker/${F} \
		${PYTHON_SITELIBDIR}/PyPlucker
.endfor
	${LN} -sf ${PYTHON_SITELIBDIR}/PyPlucker/Spider.py \
		${PREFIX}/bin/plucker-build
	${LN} -sf ${PYTHON_SITELIBDIR}/PyPlucker/PluckerDocs.py \
		${PREFIX}/bin/plucker-decode
	${LN} -sf ${PYTHON_SITELIBDIR}/PyPlucker/Decode.py \
		${PREFIX}/bin/plucker-dump
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/PluckerUserGuide.pdb \
		${WRKSRC}/*.prc ${DATADIR}
	${MKDIR} ${PREFIX}/etc/plucker
	${INSTALL_DATA} ${WRKSRC}/exclusionlist.txt \
		${PREFIX}/etc/plucker/exclusionlist.txt.sample
	${INSTALL_DATA} ${WRKSRC}/home.html \
		${PREFIX}/etc/plucker/home.html.sample
	${INSTALL_DATA} ${WRKSRC}/pluckerrc.sample \
		${PREFIX}/etc/plucker
.for F in fonts ppi xlit
	${MKDIR} ${DATADIR}/${F}
	${INSTALL_DATA} ${WRKSRC}/${F}/* ${DATADIR}/${F}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/manual
.for F in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${F} ${MAN1PREFIX}/man/man1
.endfor
.for F in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/manual/* ${DOCSDIR}/manual
.endif

.include <bsd.port.post.mk>
