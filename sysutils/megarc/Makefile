# Created by: Gerrit Beine <tux@pinguru.net>

PORTNAME=	megarc
PORTVERSION=	1.51
CATEGORIES=	sysutils
MASTER_SITES=	# not available
DISTNAME=	dr_freebsd_${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LSI Logic's MegaRAID controlling software

# Converted from RESTRICTED
LICENSE=	LSI
LICENSE_NAME=	LSI
LICENSE_TEXT=	Must be downloaded directly from the manufacturer
LICENSE_PERMS=	auto-accept

OPTIONS_DEFINE=	DOCS

USES=		dos2unix
DOS2UNIX_GLOB=	*.txt
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	sbin/megarc
PORTDOCS=	*

post-extract:
	@cd ${WRKSRC} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} 'MegaRC 1.04.zip' -C ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/megarc ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Release\ History.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	has a distribution file that is not freely available.  The binary is shipped on the Megaraid Universal Software Suite CD which accompanies any boxed LSI Logic RAID storage adaptor.  Copy ${DISTNAME}${EXTRACT_SUFX} to ${DISTDIR} and try again.  For further instructions, see http://www.freebsdwiki.net/index.php/Megarc
.endif

.include <bsd.port.post.mk>
