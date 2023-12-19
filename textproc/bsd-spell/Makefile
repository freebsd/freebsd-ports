PORTNAME=	bsd-spell
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.1
CATEGORIES=	textproc

MAINTAINER=	gbe@FreeBSD.org
COMMENT=	This is a port of the 4.4BSD spell command
WWW=		https://github.com/gbergling/bsdspell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	gbergling
GH_PROJECT=	bsdspell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/spell/spellprog ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/deroff/deroff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/usr.bin/spell/spell.sh ${STAGEDIR}${PREFIX}/bin/bspell

	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/american ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/british ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/special.4bsd ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/special.math ${STAGEDIR}${PREFIX}/share/dict
	${INSTALL_DATA} ${WRKSRC}/usr.bin/spell/stop ${STAGEDIR}${PREFIX}/share/dict

	${INSTALL_MAN} ${WRKSRC}/usr.bin/spell/spell.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/usr.bin/deroff/deroff.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
