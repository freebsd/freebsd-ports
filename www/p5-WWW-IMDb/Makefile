# New ports collection makefile for:	p5-WWW-IMDb
# Date created:				Wed Jul  17 08:00:30 2001
# Whom:					Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	IMDb
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	ftp://ftp.rhapsodyk.net/pub/devel/perl/
PKGNAMEPREFIX=	p5-WWW-
DISTNAME=	IMDb-current

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Perl interface to query the Internet Movie Database(IMDb)

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PERL_CONFIGURE=	yes

MAN3=		IMDb.3

.include <bsd.port.mk>
