# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	smbldap-tools
PORTVERSION=	0.9.10
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://download.gna.org/smbldap-tools/sources/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Samba-LDAP management and support tools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Crypt-SmbHash>=0:security/p5-Crypt-SmbHash \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Unicode-MapUTF8>=0:converters/p5-Unicode-MapUTF8
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/a//}

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-samba-sysconfdir=${LOCALBASE}/etc \
		--with-samba-bindir=${LOCALBASE}/bin \
		--with-perl=${PERL} \
		--with-perl-libdir=sitelib
ALL_TARGET=	build
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	MIGRATION_SCRIPTS DOCS
OPTIONS_SUB=	yes
MIGRATION_SCRIPTS_DESC=	Install migration scripts

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/smbldap-config.pl

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/smbldap-tools
.for i in smbldap.conf smbldap_bind.conf
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/etc/smbldap-tools/$i.sample
.endfor

post-install-MIGRATION_SCRIPTS-on:
.for i in smbldap-migrate-pwdump-accounts smbldap-migrate-pwdump-groups \
smbldap-migrate-unix-accounts smbldap-migrate-unix-groups
	@${SED} -e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/doc/migration_scripts/$i > ${STAGEDIR}${PREFIX}/sbin/$i
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/smbldap-config.cmd ${STAGEDIR}${DOCSDIR}/smbldap-config
	${INSTALL_SCRIPT} ${WRKSRC}/smbldap-upgrade-0.9.6.cmd ${STAGEDIR}${DOCSDIR}/smbldap-upgrade-0.9.6
.for f in CONTRIBUTORS COPYING ChangeLog FILES INFRA INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.html ${STAGEDIR}${DOCSDIR}/smbldap-tools.html
	${INSTALL_DATA} ${WRKSRC}/doc/smbldap-tools.pdf ${STAGEDIR}${DOCSDIR}/smbldap-tools.pdf

.include <bsd.port.mk>
