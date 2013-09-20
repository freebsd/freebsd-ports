# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s5
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://meyerweb.com/eric/tools/s5/v/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple HTML-based presentation system

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(css|htc|html|js|txt)
USE_ZIP=	yes
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

MAN1=		s5.1
MANCOMPRESSED=	no

S5_DIR=		${PREFIX}/share/${PORTNAME}
S5_SUBDIRS=	pix primer s5-blank ui

NO_STAGE=	yes
post-extract:
		cd ${WRKSRC} && ${UNZIP_CMD} s5-blank.zip
		${SED} -e "s,/usr/local,${PREFIX}," ${FILESDIR}/s5.sh > ${WRKDIR}/s5
		${SED} -e "s,/usr/local,${PREFIX}," ${FILESDIR}/s5.1 > ${WRKDIR}/s5.1
		${FIND} ${WRKDIR} -type f -name .DS_Store -delete

do-install:
		${MKDIR} ${S5_DIR}
		(cd ${WRKDIR} && \
			${COPYTREE_SHARE} "*.html ${S5_SUBDIRS}" ${S5_DIR})
		${INSTALL_SCRIPT} ${WRKDIR}/s5 ${PREFIX}/bin/s5
		${INSTALL_DATA} ${WRKDIR}/s5.1 ${PREFIX}/man/man1/s5.1

.include <bsd.port.mk>
