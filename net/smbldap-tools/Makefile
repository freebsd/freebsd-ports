# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://download.gna.org/smbldap-tools/packages/ \
		http://download.gna.org/smbldap-tools/packages/old-Idealx-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Samba-LDAP management and support tools

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Unicode/Map8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/a//}

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure.pl
	@${PERL} -pi -e 's#/etc/samba#${PREFIX}/etc#' ${WRKSRC}/configure.pl \
							${WRKSRC}/doc/smb.conf \
							${WRKSRC}/smbldap_tools.pm
	@${PERL} -pi -e 's#/etc/smb/#${PREFIX}/etc/smb/#' ${WRKSRC}/configure.pl \
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
.for i in smbldap-groupadd smbldap-groupdel smbldap-groupmod smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-userlist smbldap-usermod smbldap-usershow smbldap-passwd smbldap-populate
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/sbin
.endfor
.for i in smbldap-migrate-pwdump-accounts smbldap-migrate-pwdump-groups smbldap-migrate-unix-accounts smbldap-migrate-unix-groups
	${INSTALL_SCRIPT} ${WRKSRC}/doc/migration_scripts/$i ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/smbldap_tools.pm ${SITE_PERL}/
	${INSTALL_DATA} ${WRKSRC}/doc/smb.conf ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/configure.pl ${EXAMPLESDIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.pdf ${DOCSDIR}/smbldap-tools.pdf
.endif

.include <bsd.port.mk>
