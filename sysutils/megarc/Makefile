# Ports collection makefile for:	megarc
# Date created:				22 June 2005
# Whom:					Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	megarc
PORTVERSION=	1.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/DistributionSystem/AssetDocument/files/support/rsa/beta/drivers/
DISTNAME=	dr_freebsd_${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	LSI Logic's MegaRAID controlling software

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386 amd64
RESTRICTED=	Must be downloaded directly from the manufacturer

PLIST_FILES=	sbin/megarc
PORTDOCS=	*

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -aqo 'MegaRC 1.04.zip'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/megarc ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Release\ History.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
