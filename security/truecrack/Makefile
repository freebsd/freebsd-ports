# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	truecrack
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	https://truecrack.googlecode.com/files/ \
		http://mirrors.rit.edu/zi/
DISTNAME=	${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Password cracker for TrueCrypt volumes

LICENSE=	GPLv3

BROKEN=		Unfetchable (google code has gone away)

USES=		gmake
CFLAGS+=	-DTC_BSD
PLIST_FILES=	bin/truecrack

DICTIONARIES=	dictionary_100k.txt dictionary_10k.txt dictionary.txt
PORTDATA=	${DICTIONARIES}

post-patch:
	@${REINPLACE_CMD} -e 's/CFLAGS =/CFLAGS +=/g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/return ;/return 0;/g' ${WRKSRC}/Main/Utils.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/truecrack ${STAGEDIR}${PREFIX}/bin
.for dict in ${DICTIONARIES}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${dict} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
