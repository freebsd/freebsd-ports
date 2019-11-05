# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	cleanfeed
PORTVERSION=	20110224
CATEGORIES=	news
MASTER_SITES=	http://www.mixmin.net/cleanfeed/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Spam filter for Usenet news servers

RUN_DEPENDS=	${LOCALBASE}/news/bin/innd:news/inn

NO_BUILD=	yes
USES=		perl5
BINOWN=		news
BINGRP=		news
SHAREOWN=	news
SHAREGRP=	news
INSTALL+=	-b
PKGDEINSTALL=	${PKGINSTALL}
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "/debug_batch_directory/s:'.*':'/var/log/cleanfeed':" ${WRKSRC}/etc/cleanfeed.local

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/news/cleanfeed/etc
.for f in bad_adult_paths bad_body bad_cancel_paths bad_from bad_groups \
		bad_hosts bad_paths bad_subject bad_url
	@${INSTALL_DATA} ${WRKSRC}/etc/${f} ${STAGEDIR}${PREFIX}/news/cleanfeed/etc
.endfor
	@${INSTALL_DATA} ${WRKSRC}/etc/cleanfeed.local \
		${STAGEDIR}${PREFIX}/news/cleanfeed/etc/cleanfeed.local.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/news/bin/filter
	@${INSTALL_DATA} ${WRKSRC}/cleanfeed ${STAGEDIR}${PREFIX}/news/bin/filter

.include <bsd.port.mk>
