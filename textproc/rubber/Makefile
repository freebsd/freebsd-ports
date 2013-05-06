# ex:ts=8
# Ports collection Makefile for:	rubber
# Date created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rubber
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/53558954/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for LaTeX and friends

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	2.5+
USE_GMAKE=	yes
USE_TEX=	tetex
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} \
		--datadir=${PYTHON_SITELIBDIR}

MANLANG=	"" fr
MAN1=		rubber.1 rubber-info.1 rubber-pipe.1
INFO=		rubber

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/rubber ! -type d | ${SED} \
		's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/rubber -type d | ${SORT} -r | ${SED} \
		's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
