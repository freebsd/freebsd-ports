PORTNAME=	flexbackup
PORTVERSION=	1.2.1
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		http://www.reynoldsnet.org/flexbackup/tarball/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl-based flexible backup system that can use dump/afio/cpio/tar
WWW=		https://flexbackup.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gtar:archivers/gtar

USES=		cpe perl5
MAKE_ARGS=	PERLPATH=${PERL} CONFFILE=${PREFIX}/etc/flexbackup.conf
TAR_CMD=	${PREFIX}/bin/gtar
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	AFIO BUFFER MBUFFER ZIP DOCS
AFIO_DESC=	Enable afio support
BUFFER_DESC=	Enable buffer support
MBUFFER_DESC=	Enable mbuffer support
ZIP_DESC=	Enable zip support

AFIO_RUN_DEPENDS=	afio:sysutils/afio
BUFFER_RUN_DEPENDS=	buffer:misc/buffer
MBUFFER_RUN_DEPENDS=	mbuffer:misc/mbuffer
ZIP_RUN_DEPENDS=	zip:archivers/zip

DOCLIST=	CHANGES CREDITS README TODO faq.html

post-patch:
	@${REINPLACE_CMD} -e 's|%%TAR_CMD%%|'${TAR_CMD}'|g' \
		${WRKSRC}/flexbackup.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fb.install \
		${STAGEDIR}${PREFIX}/bin/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf \
		${STAGEDIR}${PREFIX}/etc/flexbackup.conf.sample
	${INSTALL_MAN} ${WRKSRC}/flexbackup.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/flexbackup.conf.5 \
		${STAGEDIR}${PREFIX}/share/man/man5

post-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCLIST}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
