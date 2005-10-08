# New ports collection makefile for:	py-tofu
# Date created:				2005-10-05
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	tofu
PORTVERSION=	0.2
CATEGORIES=	net python
MASTER_SITES=	http://download.gna.org/soya/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Tofu-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Tofu is a practical high-level network game engine

DIST_SUBDIR=	python
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_TWISTED=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/Tofu-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-tofu

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
