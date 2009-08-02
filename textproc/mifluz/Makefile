# New ports collection makefile for:	GNU/mifluz
# Date created:				07 June 2002
# Whom:					Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	mifluz
PORTVERSION=	0.24.0
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to build and query a full text inverted index

USE_GNOME=	gnomehack gnometarget
USE_BISON=	build
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-unac
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

MAN1=		htdb_dump.1 htdb_stat.1 htdb_load.1 mifluz-config.1 \
		mifluzdump.1 mifluzload.1 mifluzsearch.1 mifluzdict.1
MAN3=		WordContext.3 WordList.3 WordDict.3 WordListOne.3 \
		WordKey.3 WordKeyInfo.3 WordType.3 WordDBInfo.3 \
		WordRecordInfo.3 WordRecord.3 WordReference.3 WordCursor.3 \
		WordCursorOne.3 WordMonitor.3 Configuration.3 mifluz.3
INFO=		mifluz

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE -pthread|${PTHREAD_CFLAGS}|g' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
