# New ports collection makefile for:	amavisd-new
# Date created:				05 Jun 2002
# Whom:					Christopher K Davis (ckd-freebsd@ckdhr.com)
#
# $FreeBSD$
#
# Based on amavisd ports makefile.

PORTNAME=	amavisd-new
PORTVERSION=	20030616.p6
CATEGORIES=	security
MASTER_SITES=	http://www.ijs.si/software/amavisd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-p/}

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Performance-enhanced daemonized version of amavis-perl

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
		${LOCALBASE}/bin/unfreeze:${PORTSDIR}/archivers/freeze \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/lzop:${PORTSDIR}/archivers/lzop \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo

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

SED_SCRIPT=	-e 's,%%AMAVISUSER%%,${AMAVISUSER},g' \
		-e 's,%%AMAVISGROUP%%,${AMAVISGROUP},g' \
		-e 's,%%AMAVISDIR%%,${AMAVISDIR},g' \
		-e 's,%%AMAVISQUARANTINE%%,${AMAVISQUARANTINE},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

pre-build:
	for file in amavisd.sh amavis-milter.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done
	for file in amavisd.conf amavisd; do \
		${SED} ${SED_SCRIPT} < ${WRKSRC}/$${file} > ${WRKDIR}/$${file}; \
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
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.conf ${PREFIX}/etc/amavisd.conf-dist
	${INSTALL_SCRIPT} ${WRKDIR}/amavisd.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in AAAREADME.first INSTALL LICENSE RELEASE_NOTES README_FILES/*
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/UNIX.pm:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
