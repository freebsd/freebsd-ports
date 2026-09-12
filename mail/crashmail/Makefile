PORTNAME=      crashmail
PORTVERSION=   1.7
CATEGORIES=    mail

MAINTAINER=    ervras@aim.com
COMMENT=       Fidonet tosser with JAM messagebase support and FTN message editor

LICENSE=       GPLv2
LICENSE_FILE=  ${WRKSRC}/LICENSE

USES=          gmake ncurses
USE_GITHUB=    yes
GH_ACCOUNT=    skbn
GH_PROJECT=    crashmail
GH_TAGNAME=    main

MAKE_ARGS=     CFLAGS="${CFLAGS}"

do-build:
	(cd ${WRKSRC} && ${GMAKE} bsd)
	(cd ${WRKSRC}/crashedit && ${GMAKE} -f Makefile.unix)

do-install:
.for bin in crashmail crashexport crashgetnode crashlist crashlistout crashmaint crashstats crashwrite
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${bin} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/crashedit ${STAGEDIR}${PREFIX}/bin/
.for man in crashmail.1 crashexport.1 crashgetnode.1 crashlist.1 crashlistout.1 crashmaint.1 crashstats.1 crashwrite.1
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${STAGEDIR}${PREFIX}/share/man/man1/
.endfor
	${INSTALL_MAN} ${FILESDIR}/crashedit.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_DATA} ${WRKSRC}/crashedit/crashedit.conf.example ${STAGEDIR}${PREFIX}/etc/crashedit.conf.sample

.include <bsd.port.mk>
