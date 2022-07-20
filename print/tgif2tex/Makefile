PORTNAME=	tgif2tex
PORTVERSION=	2.13
PORTREVISION=	4
CATEGORIES+=	print
MASTER_SITES=	http://www.cs.hiroshima-u.ac.jp/~nakano/tgif2tex/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Converting texts in figure by tgif to LaTeX commands

LICENSE=	GPLv2

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	tgif2tex
NO_BUILD=	yes
PLIST_FILES=	bin/tgif2tex
PORTDOCS=	how-to-use.dvi how-to-use.ps how-to-use.tex \
		example.obj example.tex \
		original.dps original.tps \
		pythagoras.dps pythagoras.tps \
		sample1.obj sample1.ps \
		sample2.1.dps sample2.1.tps \
		sample2.2.dps sample2.2.tps \
		sample2.3.dps sample2.3.tps \
		sample2.dvi sample2.tex sample2.obj sample2.ps
OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/tgif2tex

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tgif2tex ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
