# vi: ts=8:sw=8:noexpandtab:
# New ports collection makefile for:	otrs
# Date created:		29 June 2006
# Whom:			Nick Barkas <snb@threerings.net>
#
# $FreeBSD$
#

PORTNAME=	otrs
PORTVERSION=	2.0.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.otrs.org/pub/otrs/ \
		ftp://ftp.gwdg.de/pub/misc/otrs/ \
		ftp://ftp.samurai.com/pub/otrs/ \
		http://mirror.xaranet.de/otrs/ \
		http://otrs.mirror.netmonic.com/ \
		http://www.linuxshop.us/otrs/
DISTNAME=	${PORTNAME}-${PORTVERSION}-01

MAINTAINER=	snb@threerings.net
COMMENT=	Open Ticket Request System

RUN_DEPENDS=	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Date/Pcalc.pm:${PORTSDIR}/devel/p5-Date-Pcalc \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL

USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

OTRSUSER?=	otrs
OTRSUID?=	117
WWWUSER?=	www
WWWGROUP?=	www
OTRSDIR?=	www/otrs
OTRSHOME=	${PREFIX}/${OTRSDIR}
SUB_FILES=	pkg-install
SUB_LIST+=	OTRSUSER=${OTRSUSER} OTRSUID=${OTRSUID} OTRSHOME=${OTRSHOME} \
		WWWUSER=${WWWUSER} WWWGROUP=${WWWGROUP}
PLIST_SUB=	OTRSDIR=${OTRSDIR}

OPTIONS=	MYSQL "MySQL database support" on \
		PGSQL "PostgreSQL database support" off \
		LDAP "LDAP support" on \
		STATS "Statistics support" on

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.if !defined(WITHOUT_STATS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
.endif

do-install:
	${MKDIR} ${OTRSHOME}
	${RM} -f ${WRKSRC}/Kernel/Config.pm.dist.orig
	${CP} -R ${WRKSRC}/Kernel ${OTRSHOME}
	${RM} -f ${WRKSRC}/bin/SetPermissions.sh.orig
	${CP} -R ${WRKSRC}/bin ${OTRSHOME}
	${CP} -R ${WRKSRC}/scripts ${OTRSHOME}
	${CP} -R ${WRKSRC}/var ${OTRSHOME}
	${INSTALL_DATA} ${WRKSRC}/.fetchmailrc.dist ${OTRSHOME}
	${INSTALL_DATA} ${WRKSRC}/.mailfilter.dist ${OTRSHOME}
	${INSTALL_DATA} ${WRKSRC}/.procmailrc.dist ${OTRSHOME}
	@if [ ! -f ${OTRSHOME}/Kernel/Config.pm ]; then ${CP} -p \
		${OTRSHOME}/Kernel/Config.pm.dist ${OTRSHOME}/Kernel/Config.pm; fi
	@if [ ! -f ${OTRSHOME}/Kernel/Config/GenericAgent.pm ]; then ${CP} -p \
		${OTRSHOME}/Kernel/Config/GenericAgent.pm.dist \
		${OTRSHOME}/Kernel/Config/GenericAgent.pm; fi
	@if [ ! -f ${OTRSHOME}/.procmailrc ]; then ${CP} -p \
		${OTRSHOME}/.procmailrc.dist ${OTRSHOME}/.procmailrc; fi

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's|%%OTRSHOME%%|${OTRSHOME}|g' -e \
		's|%%DOCSDIR%%|${DOCSDIR}|g' < ${PKGDIR}/pkg-message | \
		fmt 75 79 | ${SED} -e 's/^\.//' > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
