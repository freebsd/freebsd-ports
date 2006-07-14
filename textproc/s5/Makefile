# New ports collection makefile for:	s5
# Date created:			28 October 2005
# Whom:				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	s5
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.meyerweb.com/eric/tools/s5/v/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A simple HTML-based presentation system

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_DOS2UNIX=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

S5_DIR=		${PREFIX}/share/${PORTNAME}
S5_SUBDIRS=	pix primer s5-blank ui

post-extract:
		cd ${WRKSRC} && ${UNZIP_CMD} s5-blank.zip
		${SED} -e "s,/usr/local,${PREFIX}," ${FILESDIR}/s5-blank.sh > ${WRKDIR}/s5-blank.sh
		${FIND} ${WRKDIR} -type f -name .DS_Store -delete

do-install:
		${MKDIR} ${S5_DIR}
		${CP} ${WRKDIR}/*.html ${S5_DIR}/
.for i in ${S5_SUBDIRS}
		${CP} -Rp ${WRKDIR}/$i/ ${S5_DIR}/$i/
.endfor
		${INSTALL_SCRIPT} ${WRKDIR}/s5-blank.sh ${PREFIX}/bin/s5-blank

.include <bsd.port.mk>
