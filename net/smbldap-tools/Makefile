# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.9.5
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://download.gna.org/smbldap-tools/packages/ \
		http://download.gna.org/smbldap-tools/packages/old-Idealx-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Samba-LDAP management and support tools

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Unicode/Map8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/a//}

USE_PERL5=	yes
NO_BUILD=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS=	MIGRATION_SCRIPTS	"Install migration scripts"	off \
		PDF_DOC			"Install PDF documentation"	off

.include <bsd.port.pre.mk>

.if defined(WITH_MIGRATION_SCRIPTS)
PLIST_SUB+=	MIGRATION_SCRIPTS=""
.else
PLIST_SUB+=	MIGRATION_SCRIPTS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e "s|/etc/samba|${PREFIX}/etc|g" \
			-e "s|/etc/smb/|${PREFIX}/etc/smb/|g" \
			${WRKSRC}/configure.pl \
			${WRKSRC}/doc/smb.conf \
			${WRKSRC}/smbldap_tools.pm
.for i in smbldap_tools.pm smbldap-groupadd smbldap-groupdel smbldap-groupmod \
smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-userinfo \
smbldap-userlist smbldap-usermod smbldap-usershow smbldap-passwd \
smbldap-populate \
doc/migration_scripts/smbldap-migrate-pwdump-groups \
doc/migration_scripts/smbldap-migrate-unix-accounts \
doc/migration_scripts/smbldap-migrate-unix-groups \
doc/migration_scripts/smbldap-migrate-pwdump-accounts
	@${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|g" \
			-e "s|/usr/sbin|${LOCALBASE}/sbin|g" \
			-e "s|/etc/opt/IDEALX|${PREFIX}/etc|g" \
			${WRKSRC}/$i
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/smbldap-tools
.for i in smbldap.conf smbldap_bind.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/smbldap-tools/$i.sample
	@[ -f ${PREFIX}/etc/smbldap-tools/$i ] || ${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/smbldap-tools/$i
.endfor
.for i in smbldap-groupadd smbldap-groupdel smbldap-groupmod \
smbldap-groupshow smbldap-useradd smbldap-userdel smbldap-userinfo \
smbldap-userlist smbldap-usermod smbldap-usershow smbldap-passwd \
smbldap-populate
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/smbldap_tools.pm ${SITE_PERL}/
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/smb.conf ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/slapd.conf ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/configure.pl ${EXAMPLESDIR}/
.endif

.if defined(WITH_MIGRATION_SCRIPTS)
	${MKDIR} ${DOCSDIR}/migration_scripts
.for i in smbldap-migrate-pwdump-accounts smbldap-migrate-pwdump-groups \
smbldap-migrate-unix-accounts smbldap-migrate-unix-groups
	${INSTALL_SCRIPT} ${WRKSRC}/doc/migration_scripts/$i ${PREFIX}/sbin
.endfor
.endif


post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in CONTRIBUTORS COPYING ChangeLog FILES INFRA INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.html ${DOCSDIR}/smbldap-tools.html
.if defined(WITH_PDF_DOC)
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.pdf ${DOCSDIR}/smbldap-tools.pdf
.endif
.endif

.include <bsd.port.post.mk>
