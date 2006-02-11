# New ports collection makefile for:	fusefs-kmod
# Date created:				08 October 2005
# Whom:					Anish Mistry <amistry@am-productions.biz>
#
# $FreeBSD$
#

PORTNAME=	fusefs
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://fuse4bsd.creo.hu/downloads/ \
		http://am-productions.biz/docs/
PKGNAMESUFFIX=	-kmod
DISTNAME=	fuse4bsd-${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Kernel module for fuse

BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

OPTIONS=	AUTOSETUP "Automatic global config file setup" off
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"
MAN8=		mount_fusefs.8
KMODDIR=	${PREFIX}/modules
MAKE_ARGS=	KMODDIR=${KMODDIR}
SRC_BASE?=	/usr/src
STARTUP=	fuse.sh
SETUP=		setup.sh
MODULE_PATH=	`sysctl -n kern.module_path`;${KMODDIR}
TXT_DOCS=	doc.txt
HTML_DOCS=	Faq.html \
		Implementation.html \
		Quickstart.html \
		article.css \
		deplate-mini.png \
		deplate.css \
		doc.html \
		heading-navbar.css \
		home-grey.png \
		mailto.png \
		next-grey.png \
		prev-grey.png \
		remote.png \
		serif.css \
		tabbar-right.css

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		requires FreeBSD 6 or above. Please consider porting it to 5.x or even 4.x
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires the Kernel source to be installed. Set SRC_BASE if it is not in /usr/src
.endif

post-configure:
	${CP} ${LOCALBASE}/include/fuse/fuse_kernel.h ${WRKSRC}/fuse_module

pre-install:
	${MKDIR} ${KMODDIR}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP} ${PREFIX}/etc/rc.d/
.if (defined(WITH_AUTOSETUP) && !defined(BATCH) && !defined(PACKAGE_BUILDING)) \
	|| (defined(WITH_AUTOSETUP) && defined(BATCH) && !defined(PACKAGE_BUILDING))
	@${SED} -e 's|@@PREFIX@@|${PREFIX}|g' \
		${FILESDIR}/${SETUP} > ${WRKDIR}/${SETUP}
	@${ECHO} "Modifying global startup config files and loading module...";
	${SH} ${WRKDIR}/${SETUP}
.else
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%MODULE_PATH%%|${MODULE_PATH}|g" ${PKGMESSAGE}
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/kmod/html
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/plaintext_out/$i ${DOCSDIR}/kmod
.endfor
.for i in ${HTML_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/html_chunked_out/$i ${DOCSDIR}/kmod/html
.endfor
.endif

.include <bsd.port.post.mk>
