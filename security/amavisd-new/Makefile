# New ports collection makefile for:	amavisd-new
# Date created:				05 Jun 2002
# Whom:					Christopher K Davis (ckd-freebsd@ckdhr.com)
#
# $FreeBSD$
#
# Based on amavisd ports makefile.

PORTNAME=	amavisd-new
PORTVERSION=	20021227.p2
CATEGORIES=	security
MASTER_SITES=	http://www.ijs.si/software/amavisd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-p/}

MAINTAINER=	blaz@si.FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/MIME/Words.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${SITE_PERL}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

USE_PERL5_RUN=	yes

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE

AMAVISUSER?=	vscan
AMAVISGROUP?=	vscan
AMAVISDIR?=	/var/amavis
AMAVISQUARANTINE?=	/var/virusmails

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.p.+//}

.if !exists(/usr/lib/libmilter.so) && !exists(${PREFIX}/lib/libmilter.so)
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

pre-build:
	for file in amavisd.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} -e 's,%%AMAVISUSER%%,${AMAVISUSER},g' \
		       -e 's,%%AMAVISGROUP%%,${AMAVISGROUP},g' \
		       -e 's,%%AMAVISDIR%%,${AMAVISDIR},g' \
		       -e 's,%%AMAVISQUARANTINE%%,${AMAVISQUARANTINE},g' \
		       -e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		       -e 's,%%PREFIX%%,${PREFIX},g' \
	               < ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done
	${SED} -e 's,%%AMAVISUSER%%,${AMAVISUSER},g' \
	       -e 's,%%AMAVISGROUP%%,${AMAVISGROUP},g' \
	       -e 's,%%AMAVISDIR%%,${AMAVISDIR},g' \
	       -e 's,%%AMAVISQUARANTINE%%,${AMAVISQUARANTINE},g' \
		< ${WRKSRC}/amavisd.conf > ${WRKDIR}/amavisd.conf

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
.if !defined(AMAVIS_NOMILTER)
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis-milter ${PREFIX}/sbin
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.conf ${PREFIX}/etc/amavisd.conf-dist
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AAAREADME.first INSTALL LICENSE \
	README_FILES/README.customize README_FILES/README.exim_v3 \
	README_FILES/README.exim_v4 README_FILES/README.exim_v4_app \
	README_FILES/README.lookups README_FILES/README.milter \
	README_FILES/README.old README_FILES/README.old.scanners \
	README_FILES/README.performance README_FILES/README.postfix \
	README_FILES/README.sendmail RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
