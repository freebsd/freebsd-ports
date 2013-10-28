# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.7
PORTREVISION=	4
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

USES=		perl5
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${CNEWSWRK}
WRKSRC=		${WRKDIR}/c-nocem
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}
PLIST_FILES=	%%NEWSBIN%%/fastcancel %%NEWSBIN%%/c-nocem

CNEWS_PORT?=	news/cnews
#CNEWSWRK?=	${WRKDIRPREFIX}${PORTSDIR}/${CNEWS_PORT}/work
# ${.CURDIR}/../.. can be diffrent from ${PORTSDIR}
CNEWSWRK?=	${WRKDIRPREFIX}${.CURDIR}/../../${CNEWS_PORT}/work
NEWSBIN?=	${PREFIX}/libexec/cnews

.include <bsd.port.mk>
