# New ports collection makefile for:    Microsoft FrontPage Extensions
# Date created:         Sat Oct 24 16:30:00 CDT 2001
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	frontpage
PORTVERSION=	5.0.2.2623
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.microsoft.com/products/frontpage/ \
		ftp://www.westbend.net/pub/microsoft/frontpage/
DISTFILES=	${FRONTPAGE}

MAINTAINER=	freebsd-maintainer@westbend.net
COMMENT=	Microsoft Frontpage 2002 Extensions

.include <bsd.port.pre.mk>

USE_REINPLACE=	yes

ONLY_FOR_ARCHS=	i386 alpha

FP_VER=		${PORTVERSION:C|^([0-9]+)\.([0-9]+).*|\1.\2|}

.if ${ARCH} == i386
.ifdef WANT_BSDI_EXT
FRONTPAGE=	fp${FP_VER:S/.//}.bsdi.tar.Z
EXTRA_PATCHES=	${FILESDIR}/fp_install.bsdi
.if ${OSVERSION} < 4300001 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500014 )
PKGMESSAGE=	pkg-message.bsdi
.endif
.else
.if (defined(BATCH) && ${BATCH} == YES ) || !exists(/usr/lib/compat/libc.so.3)
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
.endif
FRONTPAGE=	fp${FP_VER:S/.//}.freebsd.tar.Z
.if ${OSVERSION} < 4300001 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500014 )
PKGMESSAGE=	pkg-message.freebsd
.endif
.endif
.elif ${ARCH} == alpha
FRONTPAGE=	fp${FP_VER:S/.//}.alpha.tar.Z
EXTRA_PATCHES=	${FILESDIR}/fp_install.alpha
.endif

.ifdef ALL_FP
FRONTPAGE=	fp${FP_VER:S/.//}.freebsd.tar.Z \
		fp${FP_VER:S/.//}.bsdi.tar.Z \
		fp${FP_VER:S/.//}.alpha.tar.Z
.endif

EXTRACT_ONLY=
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

BATCH?=		NO
CHMOD?=		/bin/chmod
NM=		/usr/bin/nm
CRYPT_DES!=	${NM} /usr/lib/libcrypt.a | ${GREP} -q -e "crypt_des" ; echo $$?
FP_DIR=		frontpage/version${FP_VER}
FPINSTALL=	${FP_DIR}/fp_install.sh
FPEXEC=		${FP_DIR}/apache-fp/fpexe.c
FPSETPERM=	${FP_DIR}/set_default_perms.sh
README=		${FP_DIR}/readme.htm
FPHTTPD=	${FP_DIR}/apache-fp
FPCSS=		${FP_DIR}/admin/1033/webadmin.css

MOD_FPDOCDIR=	${PREFIX}/share/doc/apache/manual/frontpage

PLIST_SUB=	FP_VER=${FP_VER}

pre-extract:
.if ${OSVERSION} < 430001 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500014 )
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "-ldescrypt"; then \
	   ${ECHO} ; \
	   ${ECHO} "WARNING: MS FrontPage Extensions requires the libdescrypt library"; \
	   ${ECHO} "  Install the libdescrypt Library, then build apache-fp"; \
	   ${ECHO} ; \
	   ${ECHO} "  FreeBSD Handbook - Security (chapter 10)"; \
	   ${ECHO} "    http://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/crypt.html"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi
.else
.if ${CRYPT_DES} == 1
	@${ECHO} 
	@${ECHO} "WARNING: MS FrontPage Extensions requires crypt_des in"
	@${ECHO} "   the /usr/lib/libcrypt library.  You will need to"
	@${ECHO} "   rebuild the libcrypt library with DES support."
.if defined(NOSECURE) || defined(NOCRYPT)
	@${ECHO}
	@${ECHO} "   You need to comment out both NOSECURE and NOCRYPT"
	@${ECHO} "   in the /etc/make.conf file before rebuilding the"
	@${ECHO} "   libcrypt library." 
.endif
	@${ECHO}
	@${FALSE}
.endif
.endif

post-extract:
	@${ECHO} "===>  Extracting FrontPage install scripts"
	cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} \
		${EXTRACT_AFTER_ARGS} ${FPINSTALL} ${FPEXEC} \
		${README} ${FPSETPERM}

post-patch:
.if !defined(PATCH_DEBUG)
	@${REINPLACE_CMD} -e 's:PREFIX:${PREFIX}:g' ${WRKDIR}/${FPINSTALL}
.endif

do-install:
	@${ECHO_MSG} "===> Untaring FrontPage Extensions to ${PREFIX}"
	@(cd ${PREFIX} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS})
	@${REINPLACE_CMD} -e 's:IMAGESDIR:../images/:g' ${PREFIX}/${FPCSS}
	@if [ -f ${PREFIX}/${FPCSS} ]; then \
		${RM} ${PREFIX}/${FPCSS}.bak ; \
	fi
	@${RM} ${PREFIX}/${FPHTTPD}/httpd
	@${MKDIR} ${MOD_FPDOCDIR}
	@${CP} ${PREFIX}/${README} ${MOD_FPDOCDIR}/index.html
	@${INSTALL_SCRIPT} ${WRKDIR}/${FPINSTALL} ${PREFIX}/${FPINSTALL}
	@${INSTALL_SCRIPT} ${WRKDIR}/${FPSETPERM} ${PREFIX}/${FPSETPERM}
	@${PREFIX}/${FPSETPERM}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
