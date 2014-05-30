# Created by: Dima Sivachenko <demon@gpad.ac.ru>
# $FreeBSD$

PORTNAME=	man2html
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://hydra.nac.uci.edu/indiv/ehood/tar/ \
		ftp://ftp.cpan.org/pub/CPAN/modules/by-authors/Earl_Hood/ \
		http://people.freebsd.org/~demon/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Convert nroff(1) man pages to HTML

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
CGIDIR=		${PREFIX}/www/cgi-bin

PLIST_FILES=	bin/man2html man/man1/man2html.1.gz www/cgi-bin/man.cgi
PLIST_DIRS=	www/cgi-bin

post-patch:
	${REINPLACE_CMD} -e "s#/usr/local/bin/perl#${PERL5}#" ${WRKSRC}/man2html
	${REINPLACE_CMD} -e "s#/usr/bin/perl5.00503#${PERL5}#" ${WRKSRC}/man.cgi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/man2html ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man2html.1 ${STAGEDIR}/${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/man.cgi ${STAGEDIR}${CGIDIR}

.include <bsd.port.mk>
