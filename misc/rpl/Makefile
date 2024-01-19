PORTNAME=	rpl
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix text replacement utility
WWW=		http://www.laffeycomputer.com/rpl.html

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/rpl share/man/man1/rpl.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rpl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rpl.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
