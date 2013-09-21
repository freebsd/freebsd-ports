# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.7
PORTREVISION=	3
CATEGORIES=	news security
MASTER_SITES=	http://sites.inka.de/~bigred/sw/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	NoCeM for C News and INN

FETCH_DEPENDS=	${DISTDIR}/c-news/c-news.tar.Z:${PORTSDIR}/${CNEWS_PORT}:checksum
BUILD_DEPENDS=	${CNEWSWRK}/conf/substitutions:${PORTSDIR}/${CNEWS_PORT}:configure
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/${CNEWS_PORT} \
		gpgv:${PORTSDIR}/security/gnupg1

NO_STAGE=	yes

WRKSRC=		${WRKDIR}/c-nocem
CNEWS_PORT?=	news/cnews
#CNEWSWRK?=	${WRKDIRPREFIX}${PORTSDIR}/${CNEWS_PORT}/work
# ${.CURDIR}/../.. can be diffrent from ${PORTSDIR}
CNEWSWRK?=	${WRKDIRPREFIX}${.CURDIR}/../../${CNEWS_PORT}/work
NEWSBIN?=	${PREFIX}/libexec/cnews
USE_GMAKE=	yes
USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${CNEWSWRK}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}

.include <bsd.port.mk>
