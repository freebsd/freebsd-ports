# Ports collection makefile for:	megarc
# Date created:				22 June 2005
# Whom:					Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	megarc
PORTVERSION=	1.51
CATEGORIES=	sysutils
MASTER_SITES=
DISTNAME=	dr_freebsd_${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	LSI Logic's MegaRAID controlling software

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"Restrictive license"
DOWNLOAD_URL=	http://www.lsilogic.com/products/megaraid/

PLIST_FILES=	sbin/megarc
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		can not be automatically fetched due to licensing restrictions. You must manually fetch the distribution files from ${DOWNLOAD_URL} (Support -> Downloads -> freebsd151), place it in ${DISTDIR} and run make again
.endif

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -qo 'MegaRC 1.04.zip'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/megarc ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Release\ History.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
