# New ports collection makefile for:	xmovie
# Date created:		20 December 1998
# Whom:			MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	xmovie
PORTVERSION=	1.3.1
CATEGORIES=	graphics linux
MASTER_SITES=	http://people.FreeBSD.org/~imura/distfiles/
# Distfile has no version info. The original site is below.
# MASTER_SITES=	http://heroine.linuxbox.com/
DISTNAME=	${PORTNAME}-i586-${PORTVERSION}

PATCH_SITES=	${RPM_MIRRORS:S/__DIR__/${STDDIR}/g}
PATCHFILES=	${RPM_LIBPNG}

MAINTAINER=	sanpei@sanpei.org

BUILD_DEPENDS=	rpm:${PORTSDIR}/misc/rpm
RUN_DEPENDS=	${LINUX_BASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	i386
DOC_DIR=	${PREFIX}/share/doc/xmovie
LINUX_BASE=	/compat/linux
NO_BUILD=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xmovie-i586

RPM_MIRRORS=            \
	ftp://ftp.freesoftware.com/pub/linux/redhat/__DIR__/ \
	ftp://ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/RedHat/__DIR__/ \
	ftp://ftp.crc.ca/mirrors/by-site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/__DIR__/ \
	ftp://mirror.nucba.ac.jp/mirror/redhat/__DIR__/ \
	ftp://ftp.is.co.za/linux/distributions/redhat/__DIR__/ \
	ftp://mirror.aarnet.edu.au/pub/linux/redhat/__DIR__/
STDDIR=		redhat-6.1/${MACHINE_ARCH}/RedHat/RPMS
RPM_LIBPNG=	libpng-1.0.3-4.i386.rpm
DBPATH=		/var/lib/rpm
LINUX_PREFIX=	/compat/linux
RPMFLAGS=	--ignoreos --root ${LINUX_PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}

do-patch:
	@${DO_NADA}

do-install:
#
# Install Linux libraries
#
	@for R in ${PATCHFILES}; do \
		${ECHO} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${INSTALL_PROGRAM} ${WRKSRC}/xmovie ${PREFIX}/bin
	@brandelf -t Linux ${PREFIX}/bin/xmovie
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg2toc ${PREFIX}/bin
	@brandelf -t Linux ${PREFIX}/bin/mpeg2toc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOC_DIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR}/README
	@${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DOC_DIR}/index.html
.endif
.include <bsd.port.mk>
