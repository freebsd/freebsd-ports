# Created by: ijliao
# $FreeBSD$

PORTNAME=	rubber
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/53558954/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for LaTeX and friends

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

NO_ARCH=	yes

USES=		gmake makeinfo python:2.7
USE_TEX=	latex
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} \
		--datadir=${PYTHONPREFIX_SITELIBDIR} --python=${PYTHON_CMD}

PLIST_SUB=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"

INFO=		rubber

post-patch:
	@${REINPLACE_CMD} -e \
		's|\($${prefix}\)$$|\1 --root="$${DESTDIR}"|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
