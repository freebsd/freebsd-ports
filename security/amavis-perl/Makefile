# New ports collection makefile for:	amavis
# Date Created:				13 Nov 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	amavis-perl
PORTVERSION=	10
CATEGORIES=	security
MASTER_SITES=	http://www.amavis.org/dist/perl/

MAINTAINER=	roman@xpert.com

BUILD_DEPENDS=	${LOCALBASE}/bin/uvscan:${PORTSDIR}/security/vscan \
		${LOCALBASE}/bin/bunzip2:${PORTSDIR}/archivers/bzip2 \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
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
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-qmail --disable-postfix --disable-exim --with-virusdir=/var/spool/quarantine --enable-relay

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavis/amavis ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/amavis
.for i in README README.exim README.postfix README.sendmail README.scanners doc/amavis.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/amavis
.endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL} _ POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
