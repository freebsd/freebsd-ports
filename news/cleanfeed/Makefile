# New ports collection makefile for:	cleanfeed
# Date created:				09 October 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cleanfeed
PORTVERSION=	20020501
CATEGORIES=	news
MASTER_SITES=	http://www.bofh.it/~md/cleanfeed/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
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

post-patch:
	@${REINPLACE_CMD} -e 's,/news,${PREFIX}/news,g' ${WRKSRC}/cleanfeed*

do-install:
.for f in bad_adult_paths bad_cancel_paths bad_hosts bad_paths cleanfeed cleanfeed.local.sample
	@${INSTALL_DATA} ${WRKSRC}/${f} ${LOCALBASE}/news/bin/filter
.endfor

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
