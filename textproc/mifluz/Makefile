# New ports collection makefile for:	GNU/mifluz
# Date created:				07 June 2002
# Whom:					Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	mifluz
PORTVERSION=	0.23.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to build and query a full text inverted index

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} --without-unac
INSTALLS_SHLIB=	yes

USE_BISON=	yes
USE_GCC=	2.95

MAN1=	htdb_dump.1 htdb_stat.1 htdb_load.1 mifluzdump.1 mifluzload.1 \
	mifluzsearch.1 mifluzdict.1
MAN3=	WordContext.3 WordList.3 WordDict.3 WordListOne.3 WordKey.3 \
	WordKeyInfo.3 WordType.3 WordDBInfo.3 WordRecordInfo.3 \
	WordRecord.3 WordReference.3 WordCursor.3 WordCursorOne.3 \
	WordMonitor.3 Configuration.3 mifluz.3
INFO=	mifluz

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} 's|-D_THREAD_SAFE -pthread|${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${PKGDIR}/pkg-message > \
	${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
