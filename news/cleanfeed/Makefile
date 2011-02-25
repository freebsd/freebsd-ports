# New ports collection makefile for:	cleanfeed
# Date created:				09 October 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cleanfeed
PORTVERSION=	20110224
CATEGORIES=	news
MASTER_SITES=	http://www.mixmin.net/cleanfeed/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Spam filter for Usenet news servers

RUN_DEPENDS=	${LOCALBASE}/news/bin/innd:${PORTSDIR}/news/inn

NO_BUILD=	yes
USE_PERL5=	yes
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
	@${INSTALL} ${_SHROWNGRP} -d ${PREFIX}/news/cleanfeed/etc
.for f in bad_adult_paths bad_body bad_cancel_paths bad_from bad_groups \
		bad_hosts bad_paths bad_subject bad_url
	@${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/news/cleanfeed/etc
.endfor
	@${INSTALL_DATA} ${WRKSRC}/etc/cleanfeed.local \
		${PREFIX}/news/cleanfeed/etc/cleanfeed.local.sample
	@${INSTALL_DATA} ${WRKSRC}/cleanfeed ${PREFIX}/news/bin/filter

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
