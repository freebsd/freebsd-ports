# New ports collection makefile for:	amavisd
# Date created:				13 May 2002
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	amavisd
PORTVERSION=	0.1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amavis
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The daemonized version of amavis-perl

BUILD_DEPENDS=	${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${SITE_PERL}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	yes

AMAVISGROUP?=	vscan
AMAVISUSER?=	vscan
MILTER_SCRIPT=
MILTER=		"@comment -- no milter script --"
SBIN_AMAVIS=	amavis
SMTPPORT?=	10025
STARTSCRIPT=	amavisd.sh
WARNADMIN?=	yes
WARNRECIP?=	no
WARNSENDER?=	no

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc	\
			--with-amavisuser=${AMAVISUSER}:${AMAVISGROUP}	\
			--with-smtp-port=${SMTPPORT}	\
			--with-warnsender=${WARNSENDER} \
			--with-warnrecip=${WARNRECIP}	\
			--with-warnadmin=${WARNADMIN}

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS=${PTHREAD_LIBS} PTHREAD_CFLAGS=${PTHREAD_CFLAGS}

RC_SCRIPTS_SUB=	AMAVISUSER=${AMAVISUSER} \
		PREFIX=${PREFIX} \
		PERL=${PERL} \
	 	RC_SUBR=${RC_SUBR}
PLIST_SUB=	SBIN_AMAVIS=${SBIN_AMAVIS} \
	 	MILTER=${MILTER}

.if !defined(WITHOUT_UVSCAN)
BUILD_DEPENDS+=	uvscan:${PORTSDIR}/security/vscan
.endif

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-all
.endif

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
MILTER_SCRIPT=	amavisd-milter
MILTER=
SBIN_AMAVIS=	amavis-milter
.else
CONFIGURE_ARGS+=	--enable-sendmail
MTA?=		sendmail
.endif

pre-fetch:
.if !defined(WITHOUT_UVSCAN)
	@${ECHO}
	@${ECHO} "Type \"make WITHOUT_UVSCAN=yes\" if you DONT use UVSCAN."
	@${ECHO}
.endif

post-patch:
.for script in amavisd ${MILTER_SCRIPT}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/${script}.sh > ${WRKSRC}/${script}.sh
.endfor
	@${PERL} -pi.orig -e 's|/etc/amavisd.conf|${PREFIX}/etc/amavisd.conf|g' ${WRKSRC}/configure ${WRKSRC}/amavis/amavisd.in ${WRKSRC}/amavis/Makefile.in

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${AMAVISUSER} ${AMAVISGROUP}

post-install:
.for script in amavisd ${MILTER_SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/${script}.sh ${PREFIX}/etc/rc.d/${script}.sh
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in FAQ INSTALL README README.exim README.milter README.postfix README.qmail README.scanners README.sendmail doc/amavis.html doc/amavis.m4 doc/amavis.png doc/amavis.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "==============================================================================="
	@${ECHO_MSG} "Please read ${DOCSDIR}/README.${MTA}"
	@${ECHO_MSG} "==============================================================================="
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
