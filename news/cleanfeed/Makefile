# New ports collection makefile for:	cleanfeed
# Date created:				09 October 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cleanfeed
PORTVERSION=	0.95.7b
CATEGORIES=	news
MASTER_SITES=	http://www.exit109.com/~jeremy/news/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	inn2.3.patch

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/news/bin/innd:${PORTSDIR}/news/inn

NO_BUILD=	yes
MAN8=		cleanfeed.8

do-install:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/cleanfeed
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${PKGDEINSTALL}
	@-${MV} ${LOCALBASE}/news/bin/filter/filter_innd.pl ${LOCALBASE}/news/bin/filter/filter_innd.pl.ORIG
	@${INSTALL_SCRIPT} ${WRKSRC}/cleanfeed ${LOCALBASE}/news/bin/filter/filter_innd.pl
	@${INSTALL_DATA} ${WRKSRC}/cleanfeed.conf ${LOCALBASE}/news/bin/filter/cleanfeed.conf
	@${INSTALL_MAN} ${WRKSRC}/cleanfeed.8 ${LOCALBASE}/man/man8/

.include <bsd.port.mk>
