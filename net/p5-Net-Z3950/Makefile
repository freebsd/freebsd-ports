# New ports collection makefile for:	p5-Net-Z3950
# Date created:				23 December 2001
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Z3950
PORTVERSION=	0.31
CATEGORIES=	net perl5
MASTER_SITES=	http://perl.z3950.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event
LIB_DEPENDS=	yaz.1:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MARC.pm:${PORTSDIR}/textproc/p5-MARC \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

MAN3=		Net::Z3950::ResultSet.3 Net::Z3950::Manager.3 \
		Net::Z3950::Tutorial.3 Net::Z3950::Record.3 \
		Net::Z3950::Connection.3 Net::Z3950::APDU.3 Net::Z3950.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
