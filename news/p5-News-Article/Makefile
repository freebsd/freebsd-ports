# New ports collection makefile for: p5-News-Article
# Version required: 1.21
# Date created: January 2, 1998
# Whom: Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.4 1998/12/02 19:55:31 billf Exp $
#

DISTNAME=	News-Article-1.21
PKGNAME=	p5-News-Article-1.21
CATEGORIES=	news perl5
MASTER_SITES=	http://www.erlenstar.demon.co.uk/perl/ \
		http://www.infonex.com/~dacroyle/freebsd/

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Net/NNTP.pm:${PORTSDIR}/net/p5-Net \
	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/PGP/Sign.pm:${PORTSDIR}/security/p5-PGP-Sign

USE_PERL5=	yes

MAN3=		News::Article.3 News::AutoReply.3 News::FormArticle.3 \
		News::FormReply.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
