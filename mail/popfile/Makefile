# New ports collection makefile for:	popfile
# Date created:		22 Feb 2004
# Whom:			matusita@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	popfile
PORTVERSION=	0.22.5
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Automatic mail classification tool, acts as a POP3 proxy

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite2.pm:${PORTSDIR}/databases/p5-DBD-SQLite2 \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

USE_ZIP=	yes
USE_PERL5_RUN=	yes

START_SCRIPTS_SUB= DATADIR=${DATADIR}

.include <bsd.port.pre.mk>

.if defined(WITH_POPFILE_SSL)
# POPFile works with IO::Socket::SSL version 1.07 (and not 0.97/0.99).
RUN_DEPENDS+=  p5-IO-Socket-SSL>=1.07:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if defined(WITH_POPFILE_XMLRPC)
RUN_DEPENDS+=  ${SITE_PERL}/XMLRPC/Transport/HTTP.pm:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.if defined(WITH_POPFILE_SOCKS)
# XXX: IO::Socket::Socks should be listed here but no ports yet. For those
# interested, check http://search.cpan.org/~reatmon/IO-Socket-Socks-0.1/.
.endif

.if defined(WITH_POPFILE_UPGRADE_FROM_0_20)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if defined(WITH_POPFILE_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.if defined(WITH_POPFILE_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/jcode.pl:${PORTSDIR}/japanese/p5-jcode.pl
PATCH_SITES+=	http://home.jp.FreeBSD.org/~matusita/distfiles/
PATCHFILES+=	popfile-${PORTVERSION}-use-jcode.pl.patch
.endif
.endif

pre-fetch:
	@${ECHO_CMD} "This port has some compile-time options:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_SSL=YES"
	@${ECHO_CMD} "        Depend SSL libraries/modules to use SSL connection to the servers."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_XMLRPC=YES"
	@${ECHO_CMD} "        Depend SOAP libraries to use POPFile as XMLRPC server."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_UPGRADE_FROM_0_20=YES"
	@${ECHO_CMD} "        Depend BerkeleyDB libraries to upgrade old POPFile corpus."
	@${ECHO_CMD} "        This option is required only for upgrading POPFile 0.20.1 or before."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_JAPANESE=YES"
	@${ECHO_CMD} "        Depend libraries to handle email that is written in Japanese."
	@${ECHO_CMD} "        Note that UI menus in Japanese is supported by default."
.if ${PERL_LEVEL} < 500800
	@${ECHO_CMD} "        For perl 5.6 users: Since POPFile uses Encode module to convert email"
	@${ECHO_CMD} "        texts that are not available on perl 5.6, a local patch is"
	@${ECHO_CMD} "        applied to this ports (uses jcode.pl for conversion)."
.endif

post-patch:
	${CHMOD} +x ${WRKSRC}/popfile.pl
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	@${SED} ${START_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/popfile.sh > ${WRKDIR}/popfile.sh
	${INSTALL_SCRIPT} ${WRKDIR}/popfile.sh ${PREFIX}/sbin
	${RM} ${WRKDIR}/popfile.sh

.include <bsd.port.post.mk>
