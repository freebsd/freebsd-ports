PORTNAME=	unicode-emoji
DISTVERSION=	15.1
CATEGORIES=	misc
MASTER_SITES=	http://www.unicode.org/Public/emoji/${DISTVERSION}/ \
		http://www.unicode.org/Public/${DISTVERSION}.0/ucd/emoji/:ucd
DISTFILES=	emoji-data.txt:ucd emoji-sequences.txt emoji-test.txt emoji-variation-sequences.txt:ucd emoji-zwj-sequences.txt
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# nothing to extract

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unicode emoji data files
WWW=		https://home.unicode.org/emoji/

LICENSE=	UNICODE
LICENSE_NAME=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT=	See https://www.unicode.org/copyright.html#License
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/unicode/emoji
.for f in ${DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f:S/:ucd$//} ${STAGEDIR}${PREFIX}/share/unicode/emoji/${f:S/:ucd$//}
.endfor

.for f in ${DISTFILES}
PLIST_FILES+=	share/unicode/emoji/${f:S/:ucd$//}
.endfor

.include <bsd.port.mk>
