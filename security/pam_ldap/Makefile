# Created by: Joe Clarke <marcus@marcuscom.com>
# $FreeBSD$

PORTNAME=	pam_ldap
PORTVERSION=	1.8.6
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
DISTNAME=	pam_ldap-${PORTVERSION:S/.//g}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Pam module for authenticating with LDAP

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
USES=		perl5 gmake
USE_PERL5=	build
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
PAM_LDAP_CONF?=	ldap.conf
CONFIGURE_ARGS=	--with-ldap-lib=openldap \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-conf-file=${PREFIX}/etc/${PAM_LDAP_CONF} \
		--with-ldap-secret-file=${PREFIX}/etc/ldap.secret

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDATA=	*.schema

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' \
		${WRKSRC}/vers_string

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.schema ${STAGEDIR}${DATADIR}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}

.include <bsd.port.mk>
