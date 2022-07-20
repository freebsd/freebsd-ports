PORTNAME=	stow
PORTVERSION=	2.3.1
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU version of Carnegie Mellon's "Depot" program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Hash-Merge>=0:textproc/p5-Hash-Merge
TEST_DEPENDS=	p5-Test-Output>0:devel/p5-Test-Output

USES=		gmake perl5 tar:bzip2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

INFO=		stow
PORTDOCS=	*
NO_ARCH=	yes

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ChangeLog README.md
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ChangeLog.OLD manual-single.html manual.pdf version.texi
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} manual-split ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
