# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=	cdrdao
PORTVERSION=	1.1.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cdrdao
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/pccts \
		dlg:${PORTSDIR}/devel/pccts

IGNORE=	"Project frozen because of License issues. See http://cdrdao.sourceforge.net/news.html for detail"

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-gtkmmtest --with-pcctsbin=${LOCALBASE}/bin \
		--with-pcctsinc=${LOCALBASE}/include/pccts

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+=	--without-scglib
.endif

.if !defined(WITH_PTHREADS) && ${OSVERSION} > 320000
CONFIGURE_ARGS+=	--without-posix-threads
.endif

pre-fetch:
	@${ECHO_MSG} "If you don't want to use Joerg Schilling's SCSI library,"
	@${ECHO_MSG} "set WITHOUT_SCGLIB=yes."
	@${ECHO_MSG} "If you want to use pthreads, set WITH_PTHREADS=yes."

post-extract:
.if ${MACHINE_ARCH} == "alpha"
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ${LN} -sf i386-freebsd-cc.rul alpha-freebsd-cc.rul)
.endif
	@${CP} ${FILESDIR}/getopt.h ${WRKSRC}/utils

post-install:
	strip ${PREFIX}/bin/cdrdao
	@${INSTALL_PROGRAM} -s ${WRKSRC}/utils/toc2cue ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/doc/cdrdao
.for i in COPYING CREDITS INSTALL README README.FreeBSD README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3 Release-1.1.4
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/cdrdao/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
