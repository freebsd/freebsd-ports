# New ports collection makefile for:   am-utils
# Date created:        2 November 2004
# Whom:                Jon Wilson <jon@phuq.co.uk>
#
# $FreeBSD$
#

PORTNAME=	am-utils
PORTVERSION=	6.1.4
PORTEPOCH=	1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/ \
		ftp://ftp.cs.umn.edu/pub/am-utils/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/am-utils/ \
		ftp://sunsite.org.uk/package/am-utils/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/amd/am-utils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Berkeley Automounter Suite of Utilities

INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15

PORTDOCS=	AUTHORS BUGS COPYING FAQ NEWS README.attrcache

.if defined(WITH_OPENLDAP) || defined(PACKAGE_BUILDING)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=yes --enable-ldflags=-L${LOCALBASE}/lib --enable-cppflags=-I${LOCALBASE}/include
PORTDOCS+=	README.ldap ldap-id.txt ldap.schema
.endif

INFO=		am-utils
MAN1=		expn.1 pawd.1
MAN5=		amd.conf.5
MAN8=		amd.8 amq.8 automount2amd.8 fixmount.8 fsinfo.8 hlfsd.8 mk-amd-map.8 wire-test.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
