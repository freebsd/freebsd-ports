# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	megarc
PORTVERSION=	1.51
CATEGORIES=	sysutils
MASTER_SITES=	# not available
DISTNAME=	dr_freebsd_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LSI Logic's MegaRAID controlling software

USES=		dos2unix
USE_ZIP=	yes
DOS2UNIX_FILES=	Release\ History.txt
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386 amd64
RESTRICTED=	Must be downloaded directly from the manufacturer

PLIST_FILES=	sbin/megarc
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	has a distribution file that is not freely available.  The binary is shipped on the Megaraid Universal Software Suite CD which accompanies any boxed LSI Logic RAID storage adaptor.  Copy ${DISTNAME}${EXTRACT_SUFX} to ${DISTDIR} and try again.  For further instructions, see http://www.freebsdwiki.net/index.php/Megarc
.endif

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} 'MegaRC 1.04.zip'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/megarc ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Release\ History.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
