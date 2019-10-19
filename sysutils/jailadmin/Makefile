# Created by: Kirk Strauser <kirk@strauser.com>
# $FreeBSD$

PORTNAME=	jailadmin
PORTVERSION=	1.9
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/jailadmin/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Jail management system with optional SNMP support

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=		SNMP DOCS
SNMP_DESC=	install the additional SNMP management components

USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	jailadmin jail-snmp jail-snmp-persist

PORTDOCS=	INSTALL README
PLIST_FILES=	etc/jailadmin.conf.sample etc/rc.d/zzz-jail.sh \
		sbin/jailadmin ${SITE_PERL_REL}/Jail.pm

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_PLIST_FILES=	sbin/jail-snmp sbin/jail-snmp-persist share/snmp/mibs/JAIL-MIB.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jail.sh ${STAGEDIR}${PREFIX}/etc/rc.d/zzz-jail.sh
	${INSTALL_DATA} ${WRKSRC}/jailadmin.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/jailadmin ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${CP} ${WRKSRC}/Jail.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

do-install-SNMP-on:
	${INSTALL_SCRIPT} ${WRKSRC}/jail-snmp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jail-snmp-persist ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/snmp/mibs
	${INSTALL_DATA} ${WRKSRC}/JAIL-MIB.txt ${STAGEDIR}${PREFIX}/share/snmp/mibs

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
