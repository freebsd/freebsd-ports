# New ports collection makefile for:    flowscan
# Date created:         Di  13 Mär 2001 08:23:55 CET
# Whom:                 andreas@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	flowscan
PORTVERSION=    1.006
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/FlowScan/
DISTFILES=	FlowScan-${PORTVERSION}.tar.gz

MAINTAINER=	andreas@freebsd.org

BUILD_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh \
		rrdtool:${PORTSDIR}/net/rrdtool \
		${LOCALBASE}/sbin/cflowd:${PORTSDIR}/net/cflowd \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Boulder/Stream.pm:${PORTSDIR}/converters/p5-Boulder \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/ConfigReader/DirectiveStyle.pm:${PORTSDIR}/devel/p5-ConfigReader \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Table.pm:${PORTSDIR}/www/p5-HTML-Table \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Cflow.pm:${PORTSDIR}/net/p5-Cflow

CFLOWD_FLOWSCAN_PATCH=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/var/flows
WRKSRC=			${WRKDIR}/FlowScan-${PORTVERSION}

pre-install:
	${MKDIR} -p ${PREFIX}/var/flows/bin

.include <bsd.port.mk>
