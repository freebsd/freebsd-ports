# Ports collection makefile for: cuse4bsd-kmod
# Date created: 21 March 2010
# Whom:         
#
# $FreeBSD$
#

PORTNAME=	cuse4bsd-kmod
PORTVERSION=	0.1.10
CATEGORIES=	multimedia kld
MASTER_SITES=	http://www.selasky.org/hans_petter/cuse4bsd/releases/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Cuse4BSD character device loopback driver for userspace

CONFLICTS=	video4bsd-kmod*

USE_BZIP2=	yes

KMODDIR=	/boot/modules
KMODNAME=	cuse4bsd
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

do-install:
	${MAKE} -C ${WRKSRC} -f ${WRKSRC}/Makefile.lib ${PLIST_SUB} install
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${KMODDIR}

.include <bsd.port.post.mk>
