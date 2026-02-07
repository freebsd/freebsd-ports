PORTNAME=	bsd-spell
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	gbe@FreeBSD.org
COMMENT=	This is a port of the 4.4BSD spell command
WWW=		https://github.com/gbergling/bsdspell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	gbergling
GH_PROJECT=	bsdspell

post-extract:
	${REINPLACE_CMD} -e 's,/usr/share/,${PREFIX}/share/,' \
	    ${WRKSRC}/usr.bin/spell/spell.sh ${WRKSRC}/usr.bin/spell/spell.1
	${REINPLACE_CMD} -E -e 's,\<SPELL\>,B&,' -e 's,\<spell\>,b&,' \
	    ${WRKSRC}/usr.bin/spell/spell.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/spell/spellprog ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/deroff/deroff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/usr.bin/spell/spell.sh ${STAGEDIR}${PREFIX}/bin/bspell

	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/american ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/british ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/special.4bsd ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/special.math ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/stop ${STAGEDIR}${PREFIX}/share/dict

	${INSTALL_MAN} ${WRKSRC}/usr.bin/spell/spell.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/bspell.1.gz
	${INSTALL_MAN} ${WRKSRC}/usr.bin/deroff/deroff.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
