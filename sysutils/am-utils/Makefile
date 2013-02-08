# Created by: Jon Wilson <jon@phuq.co.uk>
# $FreeBSD$

PORTNAME=	am-utils
PORTVERSION=	6.1.5
PORTEPOCH=	1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/ \
		ftp://ftp.cs.umn.edu/pub/am-utils/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/amd/am-utils/ \
		RINGSERVER/net/am-utils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Berkeley Automounter Suite of Utilities

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	OPENLDAP DOCS
OPTIONS_DEFAULT=OPENLDAP
OPENLDAP_DESC=	OpenLDAP support

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MAN1=		expn.1 pawd.1
MAN5=		amd.conf.5
MAN8=		amd.8 amq.8 automount2amd.8 fixmount.8 fsinfo.8 hlfsd.8 \
		mk-amd-map.8 wire-test.8
INFO=		am-utils
PORTDOCS=	AUTHORS BUGS FAQ NEWS README.attrcache

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=yes \
		--enable-ldflags=-L${LOCALBASE}/lib \
		--enable-cppflags=-I${LOCALBASE}/include
PORTDOCS+=	README.ldap ldap-id.txt ldap.schema
.else
CONFIGURE_ARGS+=--with-ldap=no
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
