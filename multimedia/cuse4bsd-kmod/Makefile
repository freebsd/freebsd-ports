# Ports collection makefile for: cuse4bsd-kmod
# Date created: 21 March 2010
# Whom:         
#
# $FreeBSD$
#

PORTNAME=	cuse4bsd-kmod
PORTVERSION=	0.1.21
PORTREVISION=	1
CATEGORIES=	multimedia kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Cuse4BSD character device loopback driver for userspace

CONFLICTS=	video4bsd-kmod*

USE_BZIP2=	yes

KMODDIR=	/boot/modules
KMODNAME=	cuse4bsd
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
USE_LDCONFIG=	yes

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

OPTIONS=	DEBUG "Build with debugging support" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.if defined(WITH_DEBUG)
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

do-install:
	${MAKE} -C ${WRKSRC} -f ${WRKSRC}/Makefile.lib ${PLIST_SUB} install
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${KMODDIR}

.include <bsd.port.post.mk>
