# New ports collection makefile for:	ubh
# Date created:			24 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	ubh
PORTVERSION=	1.5
CATEGORIES=	news graphics
MASTER_SITES=	http://ubh.sourceforge.net/download/

MAINTAINER=	dburr@FreeBSD.ORG

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net

NO_BUILD=	YES

pre-patch:
	@${MV} ${WRKSRC}/ubh ${WRKSRC}/ubh.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKSRC}/ubh.old > ${WRKSRC}/ubh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ubh ${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/ubh
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/ubh

.include <bsd.port.mk>
