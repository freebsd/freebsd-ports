PORTNAME=	textogif
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	textproc math www
MASTER_SITES=	http://www.fourmilab.ch/webtools/textogif/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl script to convert LaTeX formulas into GIFs
WWW=		https://www.fourmilab.ch/webtools/textogif/

RUN_DEPENDS=	ppmtogif:graphics/netpbm

USES=		perl5 shebangfix tex
USE_PERL5=	run
USE_TEX=	latex dvipsk

SHEBANG_FILES=	textogif

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
