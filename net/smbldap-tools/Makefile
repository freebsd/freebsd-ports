# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.8.5
CATEGORIES=	net
MASTER_SITES=	http://www.idealx.org/prj/samba/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@xbsd.org
COMMENT=	Useful package for managing users and groups in a LDAP directory

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's#/etc/samba#${PREFIX}/etc/samba#' ${WRKSRC}/configure.pl \
								${WRKSRC}/smb.conf
	${REINPLACE_CMD} -e 's#/etc/smb#${PREFIX}/etc/smb#' ${WRKSRC}/configure.pl \
							${WRKSRC}/smbldap.conf \
							${WRKSRC}/smbldap_tools.pm
	${REINPLACE_CMD} -e 's#/usr/sbin#${LOCALBASE}/sbin#' ${WRKSRC}/smbldap-passwd

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/configure.pl ${PREFIX}/etc/${PORTNAME}/
.for i in smbldap.conf smbldap_bind.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/${PORTNAME}/$i.default
.endfor
.for i in smbldap-groupadd smbldap-groupdel smbldap-groupmod smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-usermod smbldap-usershow smbldap-migrate-accounts smbldap-migrate-groups smbldap-passwd smbldap-populate
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/smbldap_tools.pm ${SITE_PERL}/
	${INSTALL_DATA} ${WRKSRC}/smb.conf ${EXAMPLESDIR}/

.include <bsd.port.mk>
