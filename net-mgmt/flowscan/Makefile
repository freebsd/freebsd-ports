# New ports collection makefile for:    flowscan
# Date created:         Di  13 Mär 2001 08:23:55 CET
# Whom:                 andreas@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	flowscan
PORTVERSION=    1.006
PORTREVISION=	5
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
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

CFLOWD_FLOWSCAN_PATCH=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/var/db/flows
WRKSRC=			${WRKDIR}/FlowScan-${PORTVERSION}

pre-install:
	@ ${MKDIR} -p ${PREFIX}/var/db/flows/bin
	@ ${MKDIR} -p ${PREFIX}/var/db/flows/graphs

post-install:
	# install sample startup script
	@ ${INSTALL_SCRIPT} ${FILESDIR}/flowscan.sh \
		 ${PREFIX}/etc/rc.d/cflowd-flowscan.sh.sample
	# overwrite cflowd startup script, since we need some additional
	# parameters !
	@ ${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample
	# install sample Makefile to generate graphs
	@ ${INSTALL_DATA} ${WRKSRC}/graphs.mf \
		${PREFIX}/var/db/flows/graphs/Makefile.sample
	# install sample config files
.for i in	CampusIO.cf Napster_subnets.boulder SubNetIO.cf flowscan.cf \
		local_nets.boulder our_subnets.boulder
	@ ${INSTALL_DATA} ${WRKSRC}/cf/${i} \
		${PREFIX}/var/db/flows/bin/${i}.sample
.endfor
	# install important docu files
	@ ${MKDIR} -p ${PREFIX}/share/doc/flowscan
	@ ${INSTALL_DATA} ${WRKSRC}/example/crontab \
		${PREFIX}/share/doc/flowscan/crontab.sample
	@ ${INSTALL_DATA} ${WRKSRC}/rc/linux/cflowd \
		${PREFIX}/share/doc/flowscan/cflowd.sample
	@ ${INSTALL_DATA} ${WRKSRC}/rc/linux/flowscan \
		${PREFIX}/share/doc/flowscan/flowscan.sample
	@ ${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/flowscan
	# install less important docu files
.if !defined(NOPORTDOCS)
	@ ${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for i in	README README.html INSTALL.html TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/flowscan
.endfor
.endif
	# installation info
	@ cat ${.CURDIR}/pkg-message

.include <bsd.port.mk>
