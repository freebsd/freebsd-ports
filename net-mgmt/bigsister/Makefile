# ports collection makefile for:	bigsister
# Date created:				25 March 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bigsister
PORTVERSION=	0.98c8
CATEGORIES=	net-mgmt
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		big-sister-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP-based network and system monitor with web interface

RUN_DEPENDS=	\
		rrdtool:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

# net-snmp provides SNMP.pm. ucd-snmp does not; requires p5-SNMP.
# Depend on net-snmp by default.
.if defined(WITH_UCDSNMP)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/p5-SNMP
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/bs-${PORTVERSION}

BS_USER?=		bs
BS_PERL_EXT?=		pl
BS_URL?=		/bs
BS_CGI_PATH?=		/cgi-bin

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

post-configure:
	@${SED} ${SED_SCRIPT} < ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d
	${RM} -f ${PREFIX}/bigsister/bin/Statusmon/DisplayCFG.pm.orig \
		 ${PREFIX}/bigsister/bin/Statusmon/bs_evgen.pm.orig

.include <bsd.port.mk>

#
# XXX: Override default prefix behaviour for GNU_CONFIGURE.
#
CONFIGURE_ARGS=		--prefix=${PREFIX}/bigsister ${CONFIGURE_TARGET}
CONFIGURE_ARGS+=	--with-cgi=${BS_CGI_PATH}
CONFIGURE_ARGS+=	--with-perlext=${BS_PERL_EXT}
CONFIGURE_ARGS+=	--with-url=${BS_URL}
CONFIGURE_ARGS+=	--with-user=${BS_USER}
