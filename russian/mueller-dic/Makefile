# New ports collection makefile for: mueller-dic
# Date created:		14 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	mueller-dic
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	russian
MASTER_SITES=	http://mueller-dic.chat.ru/
DISTFILES=	Mueller7accentGPL.tgz yusupov_mf.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Mueller English-Russian dictionary

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/mf
WRKSRC_DIC=	${WRKDIR}/usr/local/share/dict
WRKSRC_DOC=	${WRKDIR}/usr/local/share/mova

pre-install:
	# rebuild dictionary hash
	${WRKSRC}/mf -d ${WRKSRC_DIC}/Mueller7accentGPL.koi -hash

do-install:
	# install program with different name (it conflicts with teTeX)
	${INSTALL_PROGRAM} ${WRKSRC}/mf ${PREFIX}/bin/muellerfind
	@(${ECHO_CMD} "#!/bin/sh"; ${ECHO_CMD} "${PREFIX}/bin/muellerfind \
		-d ${DATADIR}/Mueller7accentGPL.koi \$$@") >${PREFIX}/bin/mueller
	@${CHMOD} ugo+x ${PREFIX}/bin/mueller

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC_DIC}/Mueller7accentGPL.koi ${DATADIR}
	${INSTALL_DATA} ${WRKSRC_DIC}/Mueller7accentGPL.koi.h ${DATADIR}

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC_DOC}/Mueller7.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD} "==============================================="
	@${ECHO_CMD} " You can look up words in dictionary with:     "
	@${ECHO_CMD} " ${PREFIX}/bin/mueller word"
	@${ECHO_CMD} "==============================================="

.include <bsd.port.mk>
