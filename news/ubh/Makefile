# New ports collection makefile for:	ubh
# Date created:			24 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	ubh
PORTVERSION=	1.0
CATEGORIES=	news graphics
MASTER_SITES=	http://www.lanois.com/ubh/download/

MAINTAINER=	dburr@FreeBSD.ORG

#RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/NNTP.pm:${PORTSDIR}/news/p5-Net-NNTP \
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc

NO_BUILD=	YES

pre-patch:
	@${MV} ${WRKSRC}/ubh ${WRKSRC}/ubh.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKSRC}/ubh.old > ${WRKSRC}/ubh
	@${MV} ${WRKSRC}/examples/.ubhrc ${WRKSRC}/examples/dot.ubhrc
	@${MV} ${WRKSRC}/examples/.newsrc ${WRKSRC}/examples/dot.newsrc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ubh ${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/ubh
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/ubh

.include <bsd.port.mk>
