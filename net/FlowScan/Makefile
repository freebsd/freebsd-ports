# New ports collection makefile for:    FlowScan
# Date created:         Di  13 Mär 2001 08:23:55 CET
# Whom:                 andreas@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	FlowScan
PORTVERSION=    1.006
CATEGORIES=	net
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/FlowScan/

MAINTAINER=	andreas@freebsd.org

BUILD_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh \
		rrdtool:${PORTSDIR}/net/rrdtool \
		cflowd:${PORTSDIR}/net/cflowd \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Boulder/Stream.pm:${PORTSDIR}/converter/p5-Boulder \
		${LOCALBASE}/lib/perl5/site_perl/${{PERL_VER}/ConfigReader/DirectiveStyle.pm:${PORTSDIR}/devel/p5-ConfigReader \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Table.pm:${PORTSDIR}/www/p5-HTML-Table \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Cflow.pm:${PORTSDIR}/net/p5-Cflow

CFLOWD_FLOWSCAN_PATCH=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/var/flows

pre-install:
	${MKDIR} -p ${PREFIX}/var/flows/bin

.include <bsd.port.mk>
