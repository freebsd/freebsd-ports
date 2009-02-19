# New ports collection makefile for:    flexbackup
# Date created:         Wed Nov  3 17:58:26 MST 1999
# Whom:                 John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	flexbackup
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Perl-based flexible backup system that can use dump/afio/cpio/tar/star

# FreeBSD 6.0 removed gtar
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

TAR_CMD=	${PREFIX}/bin/gtar

MAKE_ARGS=	PERLPATH=${PERL} CONFFILE=${PREFIX}/etc/flexbackup.conf

USE_PERL5=	yes

SUB_FILES+=	pkg-message

OPTIONS=	AFIO	"Enable afio support" Off \
		BUFFER	"Enable buffer support" Off \
		MBUFFER	"Enable mbuffer support" Off \
		STAR	"Enable star support" Off \
		ZIP	"Enable zip support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_AFIO)
RUN_DEPENDS+=	afio:${PORTSDIR}/sysutils/afio
.endif

.if defined(WITH_BUFFER)
RUN_DEPENDS+=	buffer:${PORTSDIR}/misc/buffer
.endif

.if defined(WITH_MBUFFER)
RUN_DEPENDS+=	mbuffer:${PORTSDIR}/misc/mbuffer
.endif

.if defined(WITH_STAR)
RUN_DEPENDS+=	star:${PORTSDIR}/archivers/star
.endif

.if defined(WITH_ZIP)
RUN_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
.endif

MAN1=		flexbackup.1
MAN5=		flexbackup.conf.5

post-patch:
	@${REINPLACE_CMD} -e 's|%%TAR_CMD%%|'${TAR_CMD}'|g' \
		${WRKSRC}/flexbackup.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/fb.install ${PREFIX}/bin/flexbackup
	@${INSTALL_DATA} ${WRKSRC}/flexbackup.conf ${PREFIX}/etc/flexbackup.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/flexbackup.1 ${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 ${MAN5PREFIX}/man/man5

DOCLIST=	CHANGES CREDITS README TODO faq.html

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCLIST}" ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
