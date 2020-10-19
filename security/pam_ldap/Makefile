# Created by: Joe Clarke <marcus@marcuscom.com>
# $FreeBSD$

PORTNAME=	pam_ldap
PORTVERSION=	186
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	PAM module for authenticating with LDAP

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

USES=		gmake perl5 shebangfix
USE_OPENLDAP=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-conf-file=${PREFIX}/etc/${PAM_LDAP_CONF} \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-lib=openldap \
		--with-ldap-secret-file=${PREFIX}/etc/ldap.secret
SHEBANG_FILES=	vers_string

SUB_FILES=	pkg-message

PORTDATA=	*.schema

PAM_LDAP_CONF?=	ldap.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.schema ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
