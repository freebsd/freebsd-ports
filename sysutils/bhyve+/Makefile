PORTNAME=	bhyve+
PORTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	BHyVe with unofficial extensions
WWW=		https://github.com/pgj/freebsd-bhyve-plus-port

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64
USES=		kmod uidfix

.include <bsd.port.options.mk>

SRCS=		${SRC_BASE}/sys/modules/vmm \
		${SRC_BASE}/sys/amd64/vmm \
		${SRC_BASE}/sys/conf \
		${SRC_BASE}/lib/libvmmapi \
		${SRC_BASE}/usr.sbin/bhyve \
		${SRC_BASE}/usr.sbin/bhyvectl \
		${SRC_BASE}/usr.sbin/bhyveload \
		${SRC_BASE}/share/mk \
		${SRC_BASE}/contrib/bmake/mk

.for _src in ${SRCS}
.  if !exists(${_src}) && empty(IGNORE)
IGNORE+=	requires bhyve and vmm source files in ${_src}
.  endif
.endfor

USE_GITHUB=	yes
GH_ACCOUNT=	conclusiveeng
GH_PROJECT=	lib9p
GH_TAGNAME=	7ef466772108856ee3e093735033232a6f1a3f04

USE_LDCONFIG=	yes

LIBVMMAPI_VERSION=	5.1
LIB9P_VERSION=		1.1

PLIST_SUB=		9P_SHLIB_MAJOR=${LIB9P_VERSION} \
			VMMAPI_SHLIB_MAJOR=${LIBVMMAPI_VERSION}

.if 1302000 <= ${OSVERSION} && ${OSVERSION} < 1400000
EXTRA_PATCHES=	${PATCHDIR}/freebsd-13/1
.elif 1400000 <= ${OSVERSION} && ${OSVERSION} < 1500000
EXTRA_PATCHES=		${PATCHDIR}/freebsd-14
LIBVMMAPI_VERSION=	6.1
.else
.  if empty(IGNORE)
IGNORE+=	cannot build: unsupported system
.  endif
.endif

WRKSRC=		${WRKDIR}

_LINKS=		sys/cam/ctl \
		sys/contrib/dev/acpica \
		sys/dev/e1000 \
		sys/dev/mii \
		sys/dev/usb/controller \
		sys/dev/virtio \
		sys/amd64/include \
		sys/x86/include \
		sys/libkern \
		stand/userboot

post-extract:
	@${MKDIR} ${WRKSRC}/contrib
	@cd ${WRKSRC} && ${LN} -s ../${GH_PROJECT}-${GH_TAGNAME} contrib/lib9p
.for _link in ${_LINKS}
	@${MKDIR} $$(dirname ${WRKSRC}/${_link})
	@cd ${WRKSRC} && ${LN} -s ${SRC_BASE}/${_link} ${_link}
.endfor
.for _src in ${SRCS}
	@cd ${_src} && ${COPYTREE_SHARE} . ${WRKDIR}/${_src:S/${SRC_BASE}//1}
.endfor
	@cd ${FILESDIR} && ${COPYTREE_SHARE} kernconf ${WRKSRC}

post-patch:
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} 's/%%9P_SHLIB_MAJOR%%/${LIB9P_VERSION}/g' \
			contrib/lib9p/Makefile \
			usr.sbin/bhyve/Makefile
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} 's/%%VMMAPI_SHLIB_MAJOR%%/${LIBVMMAPI_VERSION}/g' \
			lib/libvmmapi/Makefile \
			usr.sbin/bhyve/Makefile \
			usr.sbin/bhyvectl/Makefile \
			usr.sbin/bhyveload/Makefile

do-build:
	@cd ${WRKSRC}/contrib/lib9p && \
		${MAKE} SRCTOP=${WRKSRC} SYSDIR=${SRC_BASE}/sys LIB9PDIR=
.for _src in ${SRCS}
.  if exists(${_src}/Makefile)
	@cd ${WRKSRC}/${_src:S/${SRC_BASE}//1} && \
		${MAKE} SRCTOP=${WRKSRC} SYSDIR=${SRC_BASE}/sys DEBUG_FLAGS=-g \
		MK_CTF=yes KERNBUILDDIR=${WRKSRC}/kernconf
.  endif
.endfor

do-install:
	${INSTALL_LIB} ${WRKSRC}/contrib/lib9p/lib9p.so.${LIB9P_VERSION} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libvmmapi/libvmmapi.so.${LIBVMMAPI_VERSION} ${STAGEDIR}${PREFIX}/lib
.for _bin in bhyve bhyveload bhyvectl
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/${_bin}/${_bin} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/${_bin}/${_bin}.8.gz ${STAGEDIR}${PREFIX}/man/man8
.endfor
	${INSTALL_KLD} ${WRKSRC}/sys/modules/vmm/vmm.ko ${STAGEDIR}${KMODDIR}

.include <bsd.port.mk>
