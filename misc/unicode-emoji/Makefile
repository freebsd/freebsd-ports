# $FreeBSD$

PORTNAME=	unicode-emoji
DISTVERSION=	5.0
CATEGORIES=	misc
MASTER_SITES=	http://www.unicode.org/Public/emoji/${DISTVERSION}/
DISTFILES=	emoji-data.txt emoji-sequences.txt emoji-test.txt emoji-variation-sequences.txt emoji-zwj-sequences.txt
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# nothing to extract

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unicode emoji data files

LICENSE=	UNICODE
LICENSE_NAME=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT=	See https://www.unicode.org/copyright.html#License
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/unicode/emoji
.for f in ${DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${PREFIX}/share/unicode/emoji/$f
.endfor

.for f in ${DISTFILES}
PLIST_FILES+=	share/unicode/emoji/${f}
.endfor

.include <bsd.port.mk>
