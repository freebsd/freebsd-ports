# New ports collection makefile for:    flexbackup
# Date created:         Wed Nov  3 17:58:26 MST 1999
# Whom:                 John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	flexbackup
PORTVERSION=	1.2.0
PORTREVISION?=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	Perl-based flexible backup system that can use dump/afio/cpio/tar/star

MAKE_ARGS=	PERLPATH=${PERL}

USE_PERL5=	yes

.if defined(WITH_AFIO)
RUN_DEPENDS+=	afio:${PORTSDIR}/sysutils/afio
.endif

.if defined(WITH_BUFFER)
RUN_DEPENDS+=	buffer:${PORTSDIR}/misc/buffer
.endif

.if defined(WITH_STAR)
RUN_DEPENDS+=	star:${PORTSDIR}/archivers/star
.endif

.if defined(WITH_ZIP)
RUN_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
.endif

.if defined(WITH_GTAR)
RUN_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
.endif

pre-fetch:
	@${ECHO} "----------------------------------------------------------"
	@${ECHO} "This port can utilize afio, star, zip, and buffer."
	@${ECHO} "You may use the following build options to make:"
	@${ECHO}
	@${ECHO} "  WITH_AFIO=yes   enable the use of afio"
	@${ECHO} "  WITH_STAR=yes   enable the use of star"
	@${ECHO} "  WITH_ZIP=yes    enable the use of zip"
	@${ECHO} "  WITH_BUFFER=yes enable the use of buffer"
	@${ECHO}
	@${ECHO} "----------------------------------------------------------"
	@${ECHO}
	@${ECHO} "If you are using and older version of FreeBSD that does not have GNU Tar"
	@${ECHO} "imported as the system 'tar,' configure this port using WITH_GTAR=yes"
	@${ECHO} "to enable the port dependency and use the 'path' variable in the"
	@${ECHO} "flexbackup.conf file to point to 'gtar'"
	@${ECHO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fb.install ${LOCALBASE}/bin/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${LOCALBASE}/etc/flexbackup.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in CHANGES CREDITS README TODO faq.html
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:%%PREFIX%%:${PREFIX}:g'
.include <bsd.port.mk>
