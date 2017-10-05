# Created by: ijliao
# $FreeBSD$

PORTNAME=	txtbdf2ps
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://aklv.github.io/distfiles/ \
		http://oldrus-ispell.sourceforge.net/
EXTRACT_SUFX=	.txt

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Translator TXT + BDF to PS

PLIST_FILES=	bin/txtbdf2ps
USES=		perl5 shebangfix
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
SHEBANG_FILES=	${DISTNAME}.txt
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.txt ${STAGEDIR}${PREFIX}/bin/txtbdf2ps

.include <bsd.port.mk>
