PORTNAME=	crunch
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}-wordlist/${PORTNAME}-wordlist

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Charset-based wordlist generator
WWW=		https://crunch-wordlist.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:tgz

PLIST_FILES=	bin/crunch share/man/man1/crunch.1.gz ${DATADIR}/charset.lst

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/charset.lst ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
