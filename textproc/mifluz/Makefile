# New ports collection makefile for:	GNU/mifluz
# Date created:				07 June 2002
# Whom:					Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	mifluz
PORTVERSION=	0.23.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gnu.org/pub/gnu/mifluz/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libiconv.so:${PORTSDIR}/converters/libiconv

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}

GNU_CONFIGURE=	yes

INSTALLS_SHLIB= yes
LDCONFIG_DIRS=	%%PREFIX%%/lib

MAN1=	htdb_dump.1 htdb_stat.1 htdb_load.1 mifluzdump.1 mifluzload.1 \
	mifluzsearch.1 mifluzdict.1
MAN3=	WordContext.3 WordList.3 WordDict.3 WordListOne.3 WordKey.3 \
	WordKeyInfo.3 WordType.3 WordDBInfo.3 WordRecordInfo.3 \
	WordRecord.3 WordReference.3 WordCursor.3 WordCursorOne.3 \
	WordMonitor.3 Configuration.3 mifluz.3

PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${PKGDIR}/pkg-message > \
	${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
