# New ports collection makefile for: p5-News-Article
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	News-Article
PORTVERSION=	1.21
CATEGORIES=	news perl5
MASTER_SITES=	http://www.erlenstar.demon.co.uk/perl/ \
		http://www.gelemna.org/ports/
PKGNAMEPREFIX=	p5-

MAINTAINER=	croyle@gelemna.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/NNTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/PGP/Sign.pm:${PORTSDIR}/security/p5-PGP-Sign

PERL_CONFIGURE=	yes

MAN3=		News::Article.3 News::AutoReply.3 News::FormArticle.3 \
		News::FormReply.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
