# New ports collection makefile for:	popfile
# Date created:		22 Feb 2004
# Whom:			matusita@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	popfile
PORTVERSION=	0.21.2
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://home.jp.FreeBSD.org/~matusita/distfiles/
PATCHFILES=	popfile-${PORTVERSION}-apop.patch

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Automatic mail classification tool, acts as a POP3 proxy

# DBI module is also required but intentionally not listed here,
# since ports/databases/p5-DBD-SQLite knows which to be installed.
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

USE_ZIP=	yes
USE_PERL5_RUN=	yes

START_SCRIPTS_SUB= DATADIR=${DATADIR}

.include <bsd.port.pre.mk>

.if defined(WITH_POPFILE_UPGRADE_FROM_0_20)
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if defined(WITH_POPFILE_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.if defined(WITH_POPFILE_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/jcode.pl:${PORTSDIR}/japanese/p5-jcode.pl
PATCHFILES+=	popfile-${PORTVERSION}-use-jcode.pl.patch
.endif
.endif

pre-fetch:
	@${ECHO_CMD} "This port has some compile options:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_UPGRADE_FROM_0_20=YES"
	@${ECHO_CMD} "        Since v0.21.0, The corpus format Is changed from BerkeyDB to SQLite."
	@${ECHO_CMD} "        If you have old (v0.20.1 or before) corpus and want to use it with"
	@${ECHO_CMD} "        new POPFile, use this option.  BerkeleyDB module will be installed"
	@${ECHO_CMD} "        and POPFile automatically convert from the old corpus to a new one."
	@${ECHO_CMD} "        Note that this is just for _upgrade_ time only; once you have"
	@${ECHO_CMD} "        converted your corpus or you are a new user since v0.21.0,"
	@${ECHO_CMD} "        you don't need this option next time."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   * make WITH_POPFILE_JAPANESE=YES"
	@${ECHO_CMD} "        Even if POPFile supports Japanese help message, parsing Japanese"
	@${ECHO_CMD} "        email is enabled not by POPFile itself, but by KAKASI (Kanji Kana"
	@${ECHO_CMD} "        Simple Inverter.)  If you need Japanese email support, use this"
	@${ECHO_CMD} "        option.  KAKASI perl5 module is also installed."
.if ${PERL_LEVEL} < 500800
	@${ECHO_CMD} "        If you still using perl 5.6 or before, a hacky patch is also"
	@${ECHO_CMD} "        applied to POPFile itself, and install japanese/p5-jcode.pl."
.endif
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Both options just add runtime (perl) module dependencies; you can install"
	@${ECHO_CMD} "databases/p5-BerkeleyDB and/or japanese/p5-Text-Kakasi separately."
	@${ECHO_CMD} ""

post-patch:
	${CHMOD} +x ${WRKSRC}/popfile.pl
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	@${SED} ${START_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/popfile.sh > ${WRKDIR}/popfile.sh
	${INSTALL_SCRIPT} ${WRKDIR}/popfile.sh ${PREFIX}/sbin

.include <bsd.port.post.mk>
