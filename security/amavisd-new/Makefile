# New ports collection makefile for:	amavisd-new
# Date created:				05 Jun 2002
# Whom:					Christopher K Davis (ckd-freebsd@ckdhr.com)
#
# $FreeBSD$
#
# Based on amavisd ports makefile.

PORTNAME=	amavisd-new
PORTVERSION=	20020517
CATEGORIES=	security
MASTER_SITES=	http://www.ijs.si/software/amavisd/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ckd-freebsd@ckdhr.com

BUILD_DEPENDS=	${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${SITE_PERL}/${PERL_ARCH}/IO/Socket/UNIX.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${SITE_PERL}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server

RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes

SITE_PERL=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
AMAVISUSER?=	vscan
AMAVISGROUP?=	vscan

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc --with-amavisuser=${AMAVISUSER}:${AMAVISGROUP}

STARTSCRIPT=	amavisd.sh

.if defined(WITH_POSTFIX)
CONFIGURE_ARGS+=	--enable-postfix
MTA?=		postfix
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.elif defined(WITH_POSTFIX_CURRENT)
CONFIGURE_ARGS+=	--enable-postfix
MTA?=		postfix
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
.elif defined(WITH_MILTER)
CONFIGURE_ARGS+=	--enable-milter
MTA?=		milter
PLIST=		${PKGDIR}/pkg-plist.milter
STARTSCRIPT=	amavisd-milter.sh
.else
CONFIGURE_ARGS+=	--enable-sendmail
MTA?=		sendmail
.endif

.if defined(WITH_SPAMASSASSIN)
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Razor/Client.pm:${PORTSDIR}/mail/razor-agents

pre-configure:
		${CP} ${WRKSRC}/amavis/amavisd.in.all ${WRKSRC}/amavis/amavisd.in
.endif

# you must define this if you have no scanners (example: to use amavisd-new only as a SpamAssassin/Razor filter)
.if defined(WITH_ALL_SCANNERS)
CONFIGURE_ARGS+=	--enable-all
.endif

post-patch:
	@${SED} 's,%%AMAVISUSER%%,${AMAVISUSER},g' ${FILESDIR}/${STARTSCRIPT} > ${WRKSRC}/${STARTSCRIPT}

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${AMAVISUSER} ${AMAVISGROUP}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTSCRIPT} ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in FAQ INSTALL README README.exim README.milter README.postfix README.qmail README.scanners README.sendmail doc/amavis.html doc/amavis.m4 doc/amavis.png doc/amavis.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "==============================================================================="
	@${ECHO} "Please read ${DOCSDIR}/README.${MTA}"
	@${ECHO} "==============================================================================="
.endif

.include <bsd.port.mk>
