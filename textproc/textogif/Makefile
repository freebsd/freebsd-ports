# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	textogif
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	textproc math www
MASTER_SITES=	http://www.fourmilab.ch/webtools/textogif/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl script to convert LaTeX formulas into GIFs

RUN_DEPENDS=	ppmtogif:graphics/netpbm

NO_BUILD=	yes
USE_TEX=	latex dvipsk
USES=		perl5 shebangfix
USE_PERL5=	run
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	textogif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
