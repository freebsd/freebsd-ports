# New ports collection makefile for:	xds-c
# Date created:		29 January 2007
# Whom:			coumarin@gmail.com
#
# $FreeBSD$
#

PORTNAME=	xds-c
PORTVERSION=	2.51
CATEGORIES=	lang linux devel
MASTER_SITES=	http://www.excelsior-usa.com/download/xds25x/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}-enduser-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	coumarin@gmail.com
COMMENT=	Excelsior Oberon-2/Modula-2 to C compiler, set up to produce native FreeBSD binaries

LIB_DEPENDS=	Xm:${PORTSDIR}/x11-toolkits/open-motif

RESTRICTED=	Excelsior forbids any redistribution

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses assembly code
USE_LINUX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/lib/C

MAKEFILE=	lib.mkf
ALL_TARGET=	#

SUB_FILES=	pkg-message

post-extract:
	@${MV} ${WRKDIR}/xds ${WRKSRC}

pre-patch:
	@${BRANDELF} -t Linux ${WRKSRC}/bin/xm ${WRKSRC}/bin/h2d

post-patch:
	@${REINPLACE_CMD} -e "s|%%XDSDIR%%|${PREFIX}/${PORTNAME}|g" \
		${WRKSRC}/bin/xmwork ${WRKSRC}/bin/xm.cfg

post-build:
	cd ${WRKSRC} && ${SETENV} PATH=${WRKSRC}/bin ./apisyms-c

do-install:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} \;
	@cd ${WRKSRC} && ${CHMOD} 755 bin/xm bin/h2d bin/xmwork bin/xdssamp samples/buildc
	@cd ${WRKDIR} && ${CAT} ${FILESDIR}/plist | \
	    ${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}
.if !defined(NOPORTDOCS)
	@cd ${WRKDIR} && ${CAT} ${FILESDIR}/plist-doc | \
	    ${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}
.endif
.for f in xm xmwork
	@${LN} -s ${PREFIX}/${PORTNAME}/bin/${f} ${PREFIX}/bin
.endfor
	@${LN} -s ${PREFIX}/${PORTNAME}/bin/h2d ${PREFIX}/bin/${PORTNAME}-h2d

.include <bsd.port.mk>
