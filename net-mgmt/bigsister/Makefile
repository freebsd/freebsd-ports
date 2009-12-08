# ports collection makefile for:	bigsister
# Date created:				25 March 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bigsister
PORTVERSION=	1.02
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=		SF/${PORTNAME}/Big%20Sister/${PORTVERSION}
DISTNAME=		big-sister-${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	SNMP-based network and system monitor with web interface

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp \
		rrdtool:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

USE_GMAKE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	${PORTNAME}.sh
NO_BUILD=	yes
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/big-sister-${PORTVERSION}

BS_USER?=	bs
BS_PERL_EXT?=	pl
BS_URL?=	/bs
BS_CGI_PATH?=	/cgi-bin
CONFIGURE_ARGS=	\
	--prefix=${PREFIX}/${PORTNAME} \
	--with-cgi=${BS_CGI_PATH} \
	--with-perlext=${BS_PERL_EXT} \
	--with-url=${BS_URL} \
	--with-user=${BS_USER}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX}/${PORTNAME} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
