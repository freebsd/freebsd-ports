PORTNAME=	crunch
PORTVERSION=	3.6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}-wordlist/${PORTNAME}-wordlist

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Charset-based wordlist generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:tgz

PLIST_FILES=	bin/crunch man/man1/crunch.1.gz %%DATADIR%%/charset.lst

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/charset.lst ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
