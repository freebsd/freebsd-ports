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

MAINTAINER=	bms@FreeBSD.org
COMMENT=	SNMP-based network and system monitor with web interface

RUN_DEPENDS=	\
		rrdtool:${PORTSDIR}/net/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/p5-SNMP \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

GNU_CONFIGURE=	yes
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
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>

#
# XXX: Override default prefix behaviour for GNU_CONFIGURE.
#
CONFIGURE_ARGS=		--prefix=${PREFIX}/bigsister ${CONFIGURE_TARGET}
CONFIGURE_ARGS+=	--with-cgi=${BS_CGI_PATH}
CONFIGURE_ARGS+=	--with-perlext=${BS_PERL_EXT}
CONFIGURE_ARGS+=	--with-url=${BS_URL}
CONFIGURE_ARGS+=	--with-user=${BS_USER}
