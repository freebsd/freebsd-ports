# Created by: Tom Sparks <tsparks@appliedops.net>
# $FreeBSD$

PORTNAME=	yali
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.appliedops.net/distfiles/ \
		http://1.618034.com/blog_data/files/
DISTNAME=	yali.v1.1.pl.txt
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	tsparks@appliedops.net
COMMENT=	YALI: Yet Another LOLCODE Interpreter

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

USES=		perl5 dos2unix shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${DISTFILES}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/yali

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${STAGEDIR}${PREFIX}/bin/yali

.include <bsd.port.mk>
