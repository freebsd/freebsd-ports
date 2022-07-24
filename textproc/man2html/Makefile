PORTNAME=	man2html
DISTVERSION=	3.1.20220714
CATEGORIES=	textproc
MASTER_SITES=	https://invisible-island.net/archives/man2html/
DISTNAME=	man2html-${DISTVERSION:E}

MAINTAINER=	fuz@fuz.su
COMMENT=	Convert nroff(1) man pages to HTML

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
SHEBANG_FILES=	man.cgi man2html

NO_ARCH=	yes
NO_BUILD=	yes
CGIDIR=		${PREFIX}/www/cgi-bin

PLIST_FILES=	bin/man2html \
		man/man1/man2html.1.gz \
		www/cgi-bin/man.cgi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/man2html ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man2html.1 ${STAGEDIR}/${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/man.cgi ${STAGEDIR}${CGIDIR}

.include <bsd.port.mk>
