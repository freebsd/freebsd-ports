# New ports collection makefile for:	popfile
# Date created:		22 Feb 2004
# Whom:			matusita@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	popfile
PORTVERSION=	1.0.1
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/2.%20POPFile%20Cross%20Platform/v${PORTVERSION}
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
USE_PERL5_RUN=	5.8.0+

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
# For backward compatibility; popfile 0.x supports Kakasi only.
WITH_POPFILE_KAKASI=YES
.endif
.if defined(WITH_POPFILE_KAKASI)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif
.if defined(WITH_POPFILE_MECAB)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MeCab.pm:${PORTSDIR}/japanese/p5-MeCab
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
	@${ECHO_CMD} "   * make WITH_POPFILE_KAKASI=YES"
	@${ECHO_CMD} "        Depend Kakasi library to handle Japanese text."
	@${ECHO_CMD} "   * make WITH_POPFILE_MECAB=YES"
	@${ECHO_CMD} "        Depend MeCab library to handle Japanese text."

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
