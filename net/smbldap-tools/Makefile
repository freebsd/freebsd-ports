# New ports collection makefile for:	smbldap-tools
# Date created:				May 8 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smbldap-tools
PORTVERSION=	0.9.7
CATEGORIES=	net
MASTER_SITES=	http://download.gna.org/smbldap-tools/sources/${PORTVERSION}/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Samba-LDAP management and support tools

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Crypt/SmbHash.pm:${PORTSDIR}/security/p5-Crypt-SmbHash \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Unicode/Map8.pm:${PORTSDIR}/converters/p5-Unicode-MapUTF8
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/a//}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	build

PORTDOCS=	*

OPTIONS=	MIGRATION_SCRIPTS	"Install migration scripts"	off \
		PDF_DOC			"Install PDF documentation"	off

CONFIGURE_ARGS+=	--with-samba-sysconfdir=${LOCALBASE}/etc \
			--with-samba-bindir=${LOCALBASE}/bin \
			--with-perl=${PERL} \
			--with-perl-libdir=sitelib

.include <bsd.port.pre.mk>

.if defined(WITH_MIGRATION_SCRIPTS)
PLIST_SUB+=	MIGRATION_SCRIPTS=""
.else
PLIST_SUB+=	MIGRATION_SCRIPTS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/smbldap-config.pl

post-install:
	@${MKDIR} ${PREFIX}/etc/smbldap-tools
.for i in smbldap.conf smbldap_bind.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/smbldap-tools/$i.sample
	@[ -f ${PREFIX}/etc/smbldap-tools/$i ] || ${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/etc/smbldap-tools/$i
.endfor

.if defined(WITH_MIGRATION_SCRIPTS)
. for i in smbldap-migrate-pwdump-accounts smbldap-migrate-pwdump-groups \
smbldap-migrate-unix-accounts smbldap-migrate-unix-groups
	@${SED} -e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/doc/migration_scripts/$i > ${PREFIX}/sbin/$i
. endfor
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/smbldap-config.cmd ${DOCSDIR}/smbldap-config
	${INSTALL_SCRIPT} ${WRKSRC}/smbldap-upgrade-0.9.6.cmd ${DOCSDIR}/smbldap-upgrade-0.9.6
.for file in CONTRIBUTORS COPYING ChangeLog FILES INFRA INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.html ${DOCSDIR}/smbldap-tools.html
.if defined(WITH_PDF_DOC)
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.pdf ${DOCSDIR}/smbldap-tools.pdf
.endif
.endif

.include <bsd.port.post.mk>
