# Created by: John Reynolds <johnjen@reynoldsnet.org>
# $FreeBSD$

PORTNAME=	flexbackup
PORTVERSION=	1.2.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Perl-based flexible backup system that can use dump/afio/cpio/tar/star

# FreeBSD 6.0 removed gtar
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

TAR_CMD=	${PREFIX}/bin/gtar

MAKE_ARGS=	PERLPATH=${PERL} CONFFILE=${PREFIX}/etc/flexbackup.conf

USES=		perl5

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	AFIO BUFFER MBUFFER STAR ZIP DOCS
AFIO_DESC=	Enable afio support
BUFFER_DESC=	Enable buffer support
MBUFFER_DESC=	Enable mbuffer support
STAR_DESC=	Enable star support
ZIP_DESC=	Enable zip support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAFIO}
RUN_DEPENDS+=	afio:${PORTSDIR}/sysutils/afio
.endif

.if ${PORT_OPTIONS:MBUFFER}
RUN_DEPENDS+=	buffer:${PORTSDIR}/misc/buffer
.endif

.if ${PORT_OPTIONS:MMBUFFER}
RUN_DEPENDS+=	mbuffer:${PORTSDIR}/misc/mbuffer
.endif

.if ${PORT_OPTIONS:MSTAR}
RUN_DEPENDS+=	star:${PORTSDIR}/archivers/star
.endif

.if ${PORT_OPTIONS:MZIP}
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
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCLIST}" ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
