# Created by: Christopher J. Ruwe
# $FreeBSD$

PORTNAME=	ess
DISTVERSION=	18.10.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/ \
		http://stat.ethz.ch/ESS/downloads/ess/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	R support for Emacsen

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	R:math/R

USES=		emacs gmake makeinfo perl5 tar:tgz
USE_PERL5=	build

NO_ARCH=	yes

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

post-install:
	@${CP} ${WRKSRC}/lisp/*.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/ess/

.include <bsd.port.mk>
