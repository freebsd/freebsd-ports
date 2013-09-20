# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	truecrack
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	https://truecrack.googlecode.com/files/ \
		http://mirrors.rit.edu/zi/
DISTNAME=	${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A password cracker for TrueCrypt volumes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GMAKE=	yes
CFLAGS+=	-DTC_BSD
PLIST_FILES=	bin/truecrack

.if !defined(NOPORTDATA)
DICTIONARIES=	dictionary_100k.txt dictionary_10k.txt dictionary.txt
PORTDATA=	${DICTIONARIES}
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/CFLAGS =/CFLAGS +=/g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/return ;/return 0;/g' ${WRKSRC}/Main/Utils.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/truecrack ${PREFIX}/bin
.if !defined(NOPORTDATA)
.for dict in ${DICTIONARIES}
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${dict} ${DATADIR}
.endfor
.endif

.include <bsd.port.mk>
