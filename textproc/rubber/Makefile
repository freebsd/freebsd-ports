# Created by: ijliao
# $FreeBSD$

PORTNAME=	rubber
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/53558954/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for LaTeX and friends

LICENSE=	GPLv2

USE_PYTHON=	2
USE_TEX=	latex
USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} \
		--datadir=${PYTHON_SITELIBDIR} --python=${PYTHON_CMD}

MANLANG=	"" fr
MAN1=		rubber.1 rubber-info.1 rubber-pipe.1
INFO=		rubber

NO_STAGE=	yes
post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/rubber ! -type d | ${SED} \
		's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/rubber -type d | ${SORT} -r | ${SED} \
		's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
