# Created by: ache
# $FreeBSD$

PORTNAME=	sarep
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=   http://ftp.vim.org/ibiblio/utils/text/
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line search and replace tool; written in Perl; handles regexps

RUN_DEPENDS=	p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/sarep

USES=		perl5 dos2unix shebangfix
SHEBANG_FILES=	sarep
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/sarep

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sarep ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
