# Created by: Christopher J. Ruwe
# $FreeBSD$

PORTNAME=	ess
DISTVERSION=	16.04
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/ \
		http://stat.ethz.ch/ESS/downloads/ess/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	R support for Emacsen

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	R:math/R

NO_ARCH=	yes

USES=		gmake makeinfo tar:tgz
USE_EMACS=	yes

INFO=		ess

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DESTDIR|#DESTDIR| ; \
		 s|^PREFIX|#PREFIX| ; \
		 s|=$$(PREFIX)|=$$(DESTDIR)$$(PREFIX)| ; \
		 s|share/info|${INFO_PATH}|' ${WRKSRC}/Makeconf
	@${REINPLACE_CMD} -e \
		'/^PDFs/s|=.*|=|' ${WRKSRC}/doc/Makefile

.include <bsd.port.mk>
