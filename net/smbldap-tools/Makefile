# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://samba.idealx.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Useful package for managing users and groups in a LDAP directory

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's#/etc/samba#${PREFIX}/etc/samba#' ${WRKSRC}/configure.pl \
								${WRKSRC}/smb.conf
	@${PERL} -pi -e 's#/etc/smb#${PREFIX}/etc/smb#' ${WRKSRC}/configure.pl \
							${WRKSRC}/smbldap.conf \
							${WRKSRC}/smbldap_tools.pm
	@${PERL} -pi -e 's#/etc/opt/IDEALX#${PREFIX}/etc#' ${WRKSRC}/smbldap_tools.pm
	@${PERL} -pi -e 's#/usr/sbin#${LOCALBASE}/sbin#' ${WRKSRC}/smbldap-passwd

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${EXAMPLESDIR}/etc
.for i in smbldap.conf smbldap_bind.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${EXAMPLESDIR}/etc/$i
	@[ -f ${PREFIX}/etc/${PORTNAME}/$i ] || ${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/${PORTNAME}/$i
.endfor
.for i in smbldap-groupadd smbldap-groupdel smbldap-groupmod smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-usermod smbldap-usershow smbldap-passwd smbldap-populate
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/sbin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/doc/smbldap-migrate-accounts ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/doc/smbldap-migrate-groups ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/smbldap_tools.pm ${SITE_PERL}/
	${INSTALL_DATA} ${WRKSRC}/smb.conf ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/configure.pl ${EXAMPLESDIR}/

.include <bsd.port.mk>
