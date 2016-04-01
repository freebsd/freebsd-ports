# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.7
PORTREVISION=	4
CATEGORIES=	news security
MASTER_SITES=	http://sites.inka.de/~bigred/sw/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	NoCeM for C News and INN

FETCH_DEPENDS=	${DISTDIR}/c-news/c-news.tar.Z:${CNEWS_PORT}:checksum
BUILD_DEPENDS=	${CNEWSWRK}/conf/substitutions:${CNEWS_PORT}:configure
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${CNEWS_PORT} \
		gpgv:security/gnupg1

USES=		perl5 gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${CNEWSWRK}
CONFIGURE_ENV+=	PERL=${PERL}
WRKSRC=		${WRKDIR}/c-nocem

PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}
PLIST_FILES=	%%NEWSBIN%%/fastcancel %%NEWSBIN%%/c-nocem

post-patch:
	${REINPLACE_CMD} -e 's|@newsbin@|${STAGEDIR}@newsbin@|' \
		${WRKSRC}/Makefile.in

pre-install:
	${MKDIR} ${STAGEDIR}${NEWSBIN}

.include <bsd.port.pre.mk>

# CNEWS_PORT can be set in Makefile.local
CNEWS_PORT?=	news/cnews
# ${.CURDIR}/../.. can be diffrent from ${PORTSDIR}
CNEWSWRK!=	${MAKE} -C ${.CURDIR}/../../${CNEWS_PORT} -V WRKSRC
NEWSBIN?=	${PREFIX}/libexec/cnews

.include <bsd.port.post.mk>
