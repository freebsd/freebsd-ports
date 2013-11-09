# $FreeBSD$

PORTNAME=	cuse4bsd-kmod
PORTVERSION=	0.1.30
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Cuse4BSD character device loopback driver for userspace

CONFLICTS=	video4bsd-kmod*

USE_BZIP2=	yes

KMODNAME=	cuse4bsd
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
USE_LDCONFIG=	yes

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

OPTIONS_DEFINE=	DEBUG

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.options.mk>

MAKE_ARGS+=" PTHREAD_LIBS=${PTHREAD_LIBS}"

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

do-install:
	${MAKE} -C ${WRKSRC} -f ${WRKSRC}/Makefile.lib ${PLIST_SUB} install
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${KMODDIR}

.include <bsd.port.mk>
