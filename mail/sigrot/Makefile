PORTNAME=	sigrot
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	SUNSITE/system/mail/misc
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Util to rotate your mail/news signature

MAKE_ARGS=	DEST="${STAGEDIR}${PREFIX}/bin" \
		MANDEST="${STAGEDIR}${PREFIX}/man/man1"

PLIST_FILES=	bin/sigrot man/man1/sigrot.1.gz

.include <bsd.port.mk>
