PORTNAME=	sgrep
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/ \
		LOCAL/jkoshy

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Grep for structured text like SGML and HTML

LICENSE=	GPLv2

PORTSCOUT=	limit:^0\.
CONFLICTS=	sgrep2-1.*

PLIST_FILES=	bin/sgrep man/man1/sgrep.1.gz share/sgreprc
# Override the install target in the supplied makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sgrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sgrep.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/sample.sgreprc ${STAGEDIR}${PREFIX}/share/sgreprc

.include <bsd.port.mk>
