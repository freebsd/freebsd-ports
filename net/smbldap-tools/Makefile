# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://samba.idealx.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Useful package for managing users and groups in a LDAP directory

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

DOC_HTML_LIST =	contents_motif.gif index.html next_motif.gif \
		previous_motif.gif smbldap-tools.html smbldap-tools001.html \
		smbldap-tools002.html smbldap-tools003.html \
		smbldap-tools004.html smbldap-tools005.html \
		smbldap-tools006.html smbldap-tools007.html \
		smbldap-tools008.html smbldap-tools009.html \
		smbldap-tools010.html

post-patch:
	@${PERL} -pi -e 's#/etc/samba#${PREFIX}/etc#' ${WRKSRC}/configure.pl \
							${WRKSRC}/smb.conf \
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
.for i in smbldap-groupadd smbldap-groupdel smbldap-groupmod smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-usermod smbldap-usershow smbldap-passwd smbldap-populate
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/sbin
.endfor
.for i in smbldap-migrate-pwdump-accounts smbldap-migrate-pwdump-groups smbldap-migrate-unix-accounts smbldap-migrate-unix-groups
	${INSTALL_SCRIPT} ${WRKSRC}/doc/$i ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/smbldap_tools.pm ${SITE_PERL}/
	${INSTALL_DATA} ${WRKSRC}/smb.conf ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/configure.pl ${EXAMPLESDIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.pdf ${DOCSDIR}/smbldap-tools.pdf
.for i in ${DOC_HTML_LIST}
	${INSTALL_DATA} ${WRKSRC}/doc/html/$i ${DOCSDIR}/html/$i
.endfor
.endif

.include <bsd.port.mk>
