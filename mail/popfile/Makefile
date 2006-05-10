# New ports collection makefile for:	popfile
# Date created:		22 Feb 2004
# Whom:			matusita@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	popfile
PORTVERSION=	0.22.4
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Automatic mail classification tool, acts as a POP3 proxy

# Use DBD::SQLite2 since POPFile doesn't support SQLite 1.x.
# See also files/patch-Bayes.pm.
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
# POPFile v0.22.4 works with IO::Socket::SSL version 0.96 but not 0.97.
#RUN_DEPENDS+=  ${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
IGNORE=		does not work with IO::Socket::SSL version 0.97
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
	@${ECHO_CMD} "This port has some compile options:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_SSL=YES"
	@${ECHO_CMD} "        POPFile supports SSL for all proxy protocols.  You may use SSL"
	@${ECHO_CMD} "        protocol to connect an actual servers.  Note that this does NOT"
	@${ECHO_CMD} "        enable POPFile to accept SSL connection from clients.  Enable
	@${ECHO_CMD} "        this option to install net/p5-SOAP-Lite."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_XMLRPC=YES"
	@${ECHO_CMD} "        Your program may communicate to POPFile via XMLRPC or SOAP."
	@${ECHO_CMD} "        Note that POPFile acts as a server, no client implementation is"
	@${ECHO_CMD} "        provided; you have to have your own client by yourself.  Enable"
	@${ECHO_CMD} "        this option to install net/p5-SOAP-Lite."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_UPGRADE_FROM_0_20=YES"
	@${ECHO_CMD} "        Since v0.21.0, The corpus format Is changed from BerkeleyDB to."
	@${ECHO_CMD} "        SQLite.  If you have old (v0.20.1 or before) corpus and upgrade to"
	@${ECHO_CMD} "        new POPFile, enable this option to install databases/p5-BerkeleyDB"
	@${ECHO_CMD} "        for upgrading your corpus.  Note that once you have converted to"
	@${ECHO_CMD} "        new SQLite corpus, you do not need this option next time."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_JAPANESE=YES"
	@${ECHO_CMD} "        Even though POPFile supports Japanese help messages, parsing"
	@${ECHO_CMD} "        Japanese email is not supported by POPFile itself, but by KAKASI"
	@${ECHO_CMD} "        (Kanji Kana Simple Inverter.)  If you need Japanese email support,"
	@${ECHO_CMD} "        enable this option to install japanese/p5-Text-Kakasi."
.if ${PERL_LEVEL} < 500800
	@${ECHO_CMD} "        If you still using perl 5.6 or before, a hacky patch (use jcode.pl"
	@${ECHO_CMD} "        instead of Encode::from_to) is applied for using POPFile."
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
