# ports collection makefile for:	bigsister
# Date created:				25 March 2004
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bigsister
PORTVERSION=	1.02
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=		SF/${PORTNAME}/Big%20Sister/${PORTVERSION}
DISTNAME=		big-sister-${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	SNMP-based network and system monitor with web interface

RUN_DEPENDS=	net-snmp>=0:${PORTSDIR}/net-mgmt/net-snmp \
		rrdtool:${PORTSDIR}/databases/rrdtool \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USE_GMAKE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	${PORTNAME}
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
