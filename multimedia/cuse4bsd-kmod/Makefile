# $FreeBSD$

PORTNAME=	cuse4bsd-kmod
PORTVERSION=	0.1.36
CATEGORIES=	multimedia
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Cuse4BSD character device loopback driver for userspace

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99

CONFLICTS=	video4bsd-kmod*

KMODNAME=	cuse4bsd
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
USES=		kmod tar:bzip2 uidfix
USE_LDCONFIG=	yes

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	HAVE_DEBUG="YES"
.endif

do-install:
	${SETENV} ${MAKE_ENV} DESTDIR="${STAGEDIR}" ${MAKE} -C ${WRKSRC} -f ${WRKSRC}/Makefile.lib ${PLIST_SUB} install
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${STAGEDIR}${KMODDIR}

.include <bsd.port.mk>
