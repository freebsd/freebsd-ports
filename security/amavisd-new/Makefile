# New ports collection makefile for:	amavisd-new
# Date created:				05 Jun 2002
# Whom:					Christopher K Davis (ckd-freebsd@ckdhr.com)
#
# $FreeBSD$
#
# Based on amavisd ports makefile.

PORTNAME=	amavisd-new
PORTVERSION=	2.3.1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://www.ijs.si/software/amavisd/ \
		http://mirrors.catpipe.net/amavisd-new/ \
		http://ftp.cfu.net/pub/amavisd-new/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-p/}

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Performance-enhanced daemonized version of amavis-perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${SITE_PERL}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/bin/unfreeze:${PORTSDIR}/archivers/freeze \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/lzop:${PORTSDIR}/archivers/lzop \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo \
		${LOCALBASE}/bin/cabextract:${PORTSDIR}/archivers/cabextract \
		${LOCALBASE}/bin/rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

USE_PERL5_RUN=	yes
USE_RC_SUBR=	yes

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE

AMAVISUSER?=	vscan
AMAVISGROUP?=	vscan
AMAVISDIR?=	/var/amavis
AMAVISQUARANTINE?=	/var/virusmails

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.p.+//}

OPTIONS=	MYSQL	"MySQL support"		off \
		PGSQL	"PgSQL support"		off \
		LDAP	"LDAP support"		off

.include <bsd.port.pre.mk>

.if !exists(/usr/lib/libmilter.a) && !exists(${PREFIX}/lib/libmilter.a)
AMAVIS_NOMILTER="@comment "
.endif

PLIST_SUB+=	AMAVIS_NOMILTER=${AMAVIS_NOMILTER}

.if defined(AMAVIS_NOMILTER)
do-build:
	@${ECHO} libmilter not available, not building amavis-milter and amavis
.else
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${AMAVISUSER} --with-runtime-dir=${AMAVISDIR}
CONFIGURE_WRKSRC=	${WRKSRC}/helper-progs
BUILD_WRKSRC=	${WRKSRC}/helper-progs
.endif

SED_SCRIPT=	-e 's,%%AMAVISUSER%%,${AMAVISUSER},g' \
		-e 's,%%AMAVISGROUP%%,${AMAVISGROUP},g' \
		-e 's,%%AMAVISDIR%%,${AMAVISDIR},g' \
		-e 's,%%AMAVISQUARANTINE%%,${AMAVISQUARANTINE},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

pre-build:
	for f in amavisd.sh amavis-milter.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${f}.tmpl > ${WRKDIR}/$${f}; \
	done
	for f in amavisd.conf amavisd.conf-sample amavisd amavisd-nanny; do \
		${SED} ${SED_SCRIPT} < ${WRKSRC}/$${f} > ${WRKDIR}/$${f}; \
	done

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
.if !defined(AMAVIS_NOMILTER)
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis-milter ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/amavis-milter.sh ${PREFIX}/etc/rc.d
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd-nanny ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.conf ${PREFIX}/etc/amavisd.conf-dist
.if !exists(${PREFIX}/etc/amavisd.conf)
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.conf ${PREFIX}/etc
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.conf-sample ${PREFIX}/etc/amavisd.conf-sample
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd.conf-default ${PREFIX}/etc/amavisd.conf-default
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AAAREADME.first INSTALL LDAP.schema LICENSE RELEASE_NOTES README_FILES/*
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.if ${PERL_LEVEL} < 500802
IGNORE=		requires perl 5.8.2 or higher
.endif

.include <bsd.port.post.mk>
