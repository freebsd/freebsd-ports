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

LICENSE=	GPLv2

RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

USES=		perl5
MAKE_ARGS=	PERLPATH=${PERL} CONFFILE=${PREFIX}/etc/flexbackup.conf
TAR_CMD=	${PREFIX}/bin/gtar

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	AFIO BUFFER MBUFFER STAR ZIP DOCS
AFIO_DESC=	Enable afio support
BUFFER_DESC=	Enable buffer support
MBUFFER_DESC=	Enable mbuffer support
STAR_DESC=	Enable star support
ZIP_DESC=	Enable zip support

AFIO_RUN_DEPENDS=	afio:${PORTSDIR}/sysutils/afio
BUFFER_RUN_DEPENDS=	buffer:${PORTSDIR}/misc/buffer
MBUFFER_RUN_DEPENDS=	mbuffer:${PORTSDIR}/misc/mbuffer
STAR_RUN_DEPENDS=	star:${PORTSDIR}/archivers/star
ZIP_RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

DOCLIST=	CHANGES CREDITS README TODO faq.html

post-patch:
	@${REINPLACE_CMD} -e 's|%%TAR_CMD%%|'${TAR_CMD}'|g' \
		${WRKSRC}/flexbackup.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/fb.install \
		${STAGEDIR}${PREFIX}/bin/flexbackup
	@${INSTALL_DATA} ${WRKSRC}/flexbackup.conf \
		${STAGEDIR}${PREFIX}/etc/flexbackup.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/flexbackup.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 \
		${STAGEDIR}${MAN5PREFIX}/man/man5

post-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCLIST}" ${STAGEDIR}${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
