# New ports collection makefile for:	amavis
# Date Created:				13 Nov 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	amavis-perl
PORTVERSION=	11
CATEGORIES=	security
MASTER_SITES=	http://www.amavis.org/dist/perl/

MAINTAINER=	svenasse@polaris.ca

BUILD_DEPENDS=	${LOCALBASE}/bin/uvscan:${PORTSDIR}/security/vscan \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo \
		${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip
.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-virusdir=/var/spool/quarantine --with-runtime-dir=/var/log/amavis \
			--with-logdir=/var/log/amavis

.if defined(WITH_QMAIL)
MTA?=	qmail
DIROWNER?=	qmailq:qmail
CONFIGURE_ARGS+=	--enable-qmail
.if exists(${LOCALBASE}/qmail/bin/qmail-send)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif
BUILD_DEPENDS+=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.if defined(MTA)
.if ${MTA} == "postfix"
DIROWNER?=	vscan:daemon
CONFIGURE_ARGS+=	--enable-postfix --enable-smtp
BUILD_DEPENDS+=	${LOCALBASE}/sbin/postfix:${PORTSDIR}/mail/postfix
.elif ${MTA} == "exim"
DIROWNER?=	root:daemon
CONFIGURE_ARGS+=	--enable-exim
BUILD_DEPENDS+=	${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}
.else
MTA?=	sendmail
DIROWNER?=	root:daemon
CONFIGURE_ARGS+=	--enable-relay
.endif

PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.${MTA}
PKGINSTALL=	${PKGDIR}/pkg-install.${MTA}
PKGMESSAGE=	${PKGDIR}/pkg-message.${MTA}

do-install:
	@${MKDIR} /var/log/amavis
	@${MKDIR} /var/spool/quarantine
	${INSTALL_SCRIPT} ${WRKSRC}/amavis/amavis ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/amavis
.for i in README README.exim README.qmail README.milter README.postfix README.sendmail README.scanners doc/amavis.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/amavis
.endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} _ POST-INSTALL
	@${CHOWN} ${DIROWNER} /var/log/amavis /var/spool/quarantine
	@${CHMOD} 0755 /var/log/amavis /var/spool/quarantine
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
