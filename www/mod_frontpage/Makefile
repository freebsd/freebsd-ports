# New ports collection makefile for:    apache mod_frontpage
# Date created:		2001/07/24
# Whom:			mb@imp.ch
#
# $FreeBSD$

PORTNAME=	mod_frontpage
PORTVERSION=	1.5.1mdk-1.3.19
CATEGORIES=	www
MASTER_SITES=	http://home.edo.uni-dortmund.de/~chripo/download/ \
		ftp://ftp.edo.uni-dortmund.de/pub/mod_frontpage/ \
		ftp://ftp.microsoft.com/products/frontpage/ \
		ftp://www.westbend.net/Mirrors/ftp.microsoft.com/Products/frontpage/ \
		http://officeupdate.microsoft.com/frontpage/wpp/serk/
DISTFILES=      ${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ${FRONTPAGE}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mbr@FreeBSD.org

AP_PORT?=	apache13

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS= i386
BATCH?=		NO

INSTALL_FILE=	${INSTALL} -c -m 555 -o bin -g bin
PKG_PREFIX=	${PREFIX}
FRONTPAGE=	fp40.bsdi.tar.Z
FP_REV=		version4.0
FPINSTALL=	frontpage/${FP_REV}/fp_install.sh
CHANGESERVER=	frontpage/${FP_REV}/change_server.sh
FPSETPERM=	frontpage/${FP_REV}/set_default_perms.sh
README=		frontpage/${FP_REV}/readme.htm
SERK=		frontpage/${FP_REV}/serk
AP_SHARE=	${PREFIX}/share/doc/apache
MOD_FPDOCDIR=	${AP_SHARE}/manual/mod/mod_frontpage

APXS=		${LOCALBASE}/sbin/apxs

.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || ${ECHO} no
.endif
.if exists(${APXS}) && ${APXS_WORKS} != no
AP_TARGET!=	${APXS} -q TARGET
AP_SYSCONF!=	${APXS} -q SYSCONFDIR
AP_INCLUDE!=	${APXS} -q INCLUDEDIR
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR
.else
AP_TARGET?=	httpd
AP_SYSCONF?=	${PREFIX}/etc/apache
AP_INCLUDE?=	${PREFIX}/include/apache
AP_LIBEXEC?=	${PREFIX}/libexec/apache
.endif

post-extract:
	@${ECHO} "===>  Extracting FrontPage install scripts"
	cd ${WRKSRC} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} \
		${EXTRACT_AFTER_ARGS} ${FPINSTALL} ${CHANGESERVER} \
		${README} ${FPSETPERM}

.if !defined(PATCH_DEBUG)
post-patch:
	@ cd ${WRKSRC} \
		&& find . -type f -name "*.orig" -print | xargs ${RM} -f
.endif

pre-configure:
	@${CP} ${WRKSRC}/DSO/Makefile.* ${WRKSRC}/

PERL_CONFIGURE= yes

pre-install:
	@(cd ${PREFIX} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS})
	@${MKDIR} ${MOD_FPDOCDIR}
	@${CP} ${PREFIX}/${README} ${MOD_FPDOCDIR}/index.html
	@${LN} -fs ${PREFIX}/${SERK} ${MOD_FPDOCDIR}/serk
	@${INSTALL_FILE} '${WRKSRC}/${FPINSTALL}' '${PREFIX}/${FPINSTALL}-dist'
	@${INSTALL_FILE} '${WRKSRC}/${CHANGESERVER}' '${PREFIX}/${CHANGESERVER}-dist'
	@${INSTALL_FILE} '${WRKSRC}/${FPSETPERM}' '${PREFIX}/${FPSETPERM}'
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh.sample ${PREFIX}/etc/rc.d/apache.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
