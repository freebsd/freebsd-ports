# New ports collection makefile for:    flowscan
# Date created:         Di  13 Mär 2001 08:23:55 CET
# Whom:                 andreas@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	flowscan
PORTVERSION=	1.006
PORTREVISION=	9
CATEGORIES=	net-mgmt
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/FlowScan/
DISTFILES=	FlowScan-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Processes IP flows recorded in cflowd-format raw flow files

BUILD_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh \
		rrdtool:${PORTSDIR}/databases/rrdtool \
		${LOCALBASE}/sbin/cflowd:${PORTSDIR}/net-mgmt/cflowd \
		${SITE_PERL}/Boulder/Stream.pm:${PORTSDIR}/converters/p5-Boulder \
		${SITE_PERL}/ConfigReader/DirectiveStyle.pm:${PORTSDIR}/devel/p5-ConfigReader \
		${SITE_PERL}/HTML/Table.pm:${PORTSDIR}/www/p5-HTML-Table \
		${SITE_PERL}/${PERL_ARCH}/Cflow.pm:${PORTSDIR}/net-mgmt/p5-Cflow \
		${SITE_PERL}/${PERL_ARCH}/Net/Patricia.pm:${PORTSDIR}/net/p5-Net-Patricia
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

BROKEN=		does not build
DEPRECATED=	has been broken for 5 months
EXPIRATION_DATE=2010-01-08

CFLOWD_FLOWSCAN_PATCH=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/var/db/flows
USE_PERL5=		yes
WRKSRC=			${WRKDIR}/FlowScan-${PORTVERSION}

pre-install:
	@ ${MKDIR} ${PREFIX}/var/db/flows/bin
	@ ${MKDIR} ${PREFIX}/var/db/flows/graphs

post-install:
	# sample startup script
	@ ${INSTALL_SCRIPT} ${FILESDIR}/flowscan.sh \
		 ${PREFIX}/etc/rc.d/cflowd-flowscan.sh.sample
	# overwrite cflowd startup script, since we need some additional
	# parameters !
	@ ${INSTALL_SCRIPT} ${FILESDIR}/cflowd.sh \
		${PREFIX}/etc/rc.d/cflowd-base.sh.sample
	# sample Makefile to generate graphs
	@ ${INSTALL_DATA} ${WRKSRC}/graphs.mf \
		${PREFIX}/var/db/flows/graphs/Makefile.sample
	# sample config files
.for i in	CampusIO.cf Napster_subnets.boulder SubNetIO.cf flowscan.cf \
		local_nets.boulder our_subnets.boulder
	@ ${INSTALL_DATA} ${WRKSRC}/cf/${i} \
		${PREFIX}/var/db/flows/bin/${i}.sample
.endfor
	# important docu files
	@ ${MKDIR} ${PREFIX}/share/doc/flowscan
	@ ${INSTALL_DATA} ${WRKSRC}/example/crontab \
		${PREFIX}/share/doc/flowscan/crontab.sample
	@ ${INSTALL_DATA} ${WRKSRC}/rc/linux/cflowd \
		${PREFIX}/share/doc/flowscan/cflowd.sample
	@ ${INSTALL_DATA} ${WRKSRC}/rc/linux/flowscan \
		${PREFIX}/share/doc/flowscan/flowscan.sample
	@ ${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/flowscan
	# less important docu files
.if !defined(NOPORTDOCS)
	@ ${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for i in	README README.html INSTALL.html TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/flowscan
.endfor
.endif
	# info
	@ ${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>
