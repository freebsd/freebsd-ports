# New ports collection makefile for:	p5-IC-Radius
# Date created:				27 Jun 2001
# Whom:	      				Sergey N. Voronkov <serg@tmn.ru>
#
# $FreeBSD$
#

PORTNAME=	IC-Radius
PORTVERSION=	0.4
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.innercite.com/pub/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		IC::Radius.3

.include <bsd.port.mk>
