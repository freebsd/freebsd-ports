# New ports collection makefile for:    flexbackup
# Date created:         Wed Nov  3 17:58:26 MST 1999
# Whom:                 John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	flexbackup
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	Perl-based flexible tape backup system that uses dump/afio/cpio/tar

RUN_DEPENDS=	afio:${PORTSDIR}/sysutils/afio \
		buffer:${PORTSDIR}/misc/buffer

.if defined(WITH_GTAR)
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.endif

NO_BUILD=	yes
USE_PERL5=	yes

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are using and older version of FreeBSD that does not have GNU Tar"
	@${ECHO_MSG} "imported as the system 'tar,' configure this port using WITH_GTAR=yes"
	@${ECHO_MSG} "to enable the port dependency and use the 'path' variable in the"
	@${ECHO_MSG} "flexbackup.conf file to point to 'gtar'"
	@${ECHO_MSG} ""

post-configure:
	@${CP} ${WRKSRC}/flexbackup.conf ${WRKSRC}/flexbackup.conf.sample
	@${CP} ${WRKSRC}/README ${WRKSRC}/flexbackup.README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf.sample ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/flexbackup.README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:%%PREFIX%%:${PREFIX}:g'

.include <bsd.port.mk>
