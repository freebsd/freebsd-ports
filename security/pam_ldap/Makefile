# Created by: Joe Clarke <marcus@marcuscom.com>
# $FreeBSD$

PORTNAME=	pam_ldap
PORTVERSION=	1.8.6
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
DISTNAME=	pam_ldap-${PORTVERSION:S/.//g}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A pam module for authenticating with LDAP

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
USES=		perl5
USE_PERL5=	build
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
PAM_LDAP_CONF?=	ldap.conf
CONFIGURE_ARGS=	--with-ldap-lib=openldap \
		--with-ldap-dir=${LOCALBASE} \
		--with-ldap-conf-file=${PREFIX}/etc/${PAM_LDAP_CONF} \
		--with-ldap-secret-file=${PREFIX}/etc/ldap.secret

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDATA=	*.schema

MAN5=		pam_ldap.5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' \
	    	${WRKSRC}/vers_string

pre-install:
	${MKDIR} ${DATADIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.schema ${DATADIR}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    	-e 's|%%DATADIR%%|${DATADIR}|' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
