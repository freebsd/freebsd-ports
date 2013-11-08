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
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"

INFO=		am-utils
DOCS=		AUTHORS BUGS FAQ NEWS README.attrcache

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=yes \
		--enable-ldflags=-L${LOCALBASE}/lib \
		--enable-cppflags=-I${LOCALBASE}/include
DOCS+=		README.ldap ldap-id.txt ldap.schema
PLIST_SUB+=	LDAP_DOC=""
.else
PLIST_SUB+=	LDAP_DOC="@comment "
CONFIGURE_ARGS+=--with-ldap=no
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/am-utils.info*

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
