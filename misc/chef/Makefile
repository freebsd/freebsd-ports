# $FreeBSD$

PORTNAME=	chef
PORTVERSION=	19930426
CATEGORIES=	misc
MASTER_SITES=	http://mysite.verizon.net/ebrowne72/chef/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
DISTNAME=	bork
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Feelter thet cunferts Ingleesh text tu Muck Cheenese-a

CONFLICTS=	filters-* talkfilters-*
PLIST_FILES=	bin/chef

WRKSRC=		${WRKDIR}/bork

do-build:
	(cd ${WRKSRC} && lex chef.x && ${CC} ${CFLAGS} -o chef lex.yy.c -ll)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chef ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
