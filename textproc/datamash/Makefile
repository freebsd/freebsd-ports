# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datamash
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Numeric, textual, and statistical operations on text files

LICENSE=	GPLv3+

USES=		gmake perl5
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_PERL5=	test

INFO=		${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e '/^examplesdir/s,$$(.*,${EXAMPLESDIR},' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
