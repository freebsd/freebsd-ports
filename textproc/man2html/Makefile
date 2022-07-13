# Created by: Dima Sivachenko <demon@gpad.ac.ru>

PORTNAME=	man2html
PORTVERSION=	3.1.20220109
CATEGORIES=	textproc
MASTER_SITES=	https://invisible-island.net/archives/scripts/:dickey \
		http://people.freebsd.org/~demon/:demon \
		http://fuz.su/~fuz/distfiles/man2html/:demon
DISTNAME=	other-scripts-${PORTVERSION:E}
DISTFILES=	${DISTNAME}.tgz:dickey \
		man2html3.0.1.tar.gz:demon # for cgi script and man page

MAINTAINER=	fuz@fuz.su
COMMENT=	Convert nroff(1) man pages to HTML

LICENSE=	GPLv2+

USES=		perl5 tar:tgz shebangfix
USE_PERL5=	run
SHEBANG_FILES=	man2html man.cgi

NO_ARCH=	yes
NO_BUILD=	yes
CGIDIR=		${PREFIX}/www/cgi-bin

PLIST_FILES=	bin/man2html man/man1/man2html.1.gz www/cgi-bin/man.cgi

# New upstream doesn't ship the man page and CGI script
# Rip it from the 3.0.1 tarball.
post-extract:
	@${MV} ${WRKDIR}/man2html3.0.1/doc/man2html.1 ${WRKSRC}/
	@${MV} ${WRKDIR}/man2html3.0.1/man.cgi ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/man2html ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man2html.1 ${STAGEDIR}/${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/man.cgi ${STAGEDIR}${CGIDIR}

.include <bsd.port.mk>
