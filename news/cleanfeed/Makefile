# New ports collection makefile for:	cleanfeed
# Date created:				09 October 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cleanfeed
PORTVERSION=	20011031
CATEGORIES=	news
MASTER_SITES=	http://www.bofh.it/~md/cleanfeed/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@leeym.com

RUN_DEPENDS=	${LOCALBASE}/news/bin/innd:${PORTSDIR}/news/inn \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

NO_BUILD=	yes
BINOWN=		news
BINGRP=		news
SHAREOWN=	news
SHAREGRP=	news
INSTALL+=	-b

post-patch:
.for file in cleanfeed cleanfeed.local.sample
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${file}
.endfor

do-install:
.for file in bad_adult_paths bad_cancel_paths bad_hosts bad_paths cleanfeed cleanfeed.local.sample
	@${INSTALL_DATA} ${WRKSRC}/${file} ${LOCALBASE}/news/bin/filter
.endfor
	@cd ${LOCALBASE}/news/bin/filter; ${LN} -f cleanfeed filter_innd.pl

.include <bsd.port.mk>
