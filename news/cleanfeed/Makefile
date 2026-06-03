PORTNAME=	cleanfeed
DISTVERSION=	20200402
PORTREVISION=	1
CATEGORIES=	news

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Spam filter for Usenet news servers
WWW=		https://github.com/crooks/cleanfeed

LICENSE=	ART10

FLAVORS=	inn inncurrent
FLAVOR?=	${FLAVORS:[1]}

inn_RUN_DEPENDS=		${LOCALBASE}/news/bin/innd:news/inn
inn_CONFLICTS_INSTALL=		cleanfeed-current

inncurrent_PKGNAMESUFFIX=	-current
inncurrent_RUN_DEPENDS=		${LOCALBASE}/news/bin/innd:news/inn-current
inncurrent_CONFLICTS_INSTALL=	cleanfeed

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	crooks
GH_TAGNAME=	dd177d4a3b6ea2e538da17bbb2a74772cea4a49a

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "/debug_batch_directory/s:'.*':'/var/log/cleanfeed':" ${WRKSRC}/samples/cleanfeed.local

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/news/cleanfeed/etc
.for f in bad_adult_paths bad_body bad_cancel_paths bad_from bad_groups \
		bad_hosts bad_paths bad_subject bad_url cleanfeed.local
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${STAGEDIR}${PREFIX}/news/cleanfeed/etc/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/news/bin/filter
	${INSTALL_DATA} ${WRKSRC}/cleanfeed ${STAGEDIR}${PREFIX}/news/bin/filter
	${MKDIR} ${STAGEDIR}/var/log/cleanfeed

.include <bsd.port.mk>
