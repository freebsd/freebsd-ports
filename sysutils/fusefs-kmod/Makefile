# Created by: Anish Mistry <amistry@am-productions.biz>
# $FreeBSD$

PORTNAME=	fusefs
DISTVERSION=	0.3.9-pre1.20080208
PORTREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://mercurial.creo.hu/repos/fuse4bsd-hg/index.cgi/archive/ \
    		http://mirrors.rit.edu/zi/fuse4bsd/ \
  		LOCAL/bdrewery/${PORTNAME}/
PKGNAMESUFFIX=	-kmod
DISTNAME=	${HG_SHORTREV}
DIST_SUBDIR=	fuse4bsd

MAINTAINER=	mirror176@cox.net
COMMENT=	Kernel module for fuse

BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

USE_RC_SUBR=	fusefs
KMODDIR=	${PREFIX}/modules
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		MOUNT="${SRC_BASE}/sbin/mount"
WRKSRC=		${WRKDIR}/fuse4bsd-${HG_SHORTREV}
DISABLE_SIZE=	yes

OPTIONS_DEFINE=	AUTOSETUP DOCS
AUTOSETUP_DESC=	Automatic global config file setup

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	deplate:${PORTSDIR}/textproc/ruby-deplate
.endif

SETUP=		setup.sh
HG_SHORTREV=	498acaef33b0

MAN8=		mount_fusefs.8
TXT_DOCS=	doc.text
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

.if ${OSVERSION} >= 900040
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-fuse_module__fuse_vnops.c
.endif

.if ${OSVERSION} >= 1000011
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-fuse_module__fuse_vnops.c
.endif

.if exists(${SRC_BASE}/sys/fs/fuse)
IGNORE=		Integrated into base
.endif
.if !exists(${SRC_BASE}/sbin/mount)
IGNORE=		requires the userland sources to be installed. Set SRC_BASE if it is not in /usr/src
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		Does not compile on other than i386/amd64
.endif

.if ${PORT_OPTIONS:MAUTOSETUP}
SUB_FILES+=	${SETUP}
.else
SUB_FILES+=	pkg-message
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/deplate.rb/deplate/g' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e 's|-I../inc|-I${SRC_BASE}/sys -I../inc|g' \
		${WRKSRC}/mount_fusefs/Makefile

post-configure:
	@${CP} ${LOCALBASE}/include/fuse/fuse_kernel.h ${WRKSRC}/fuse_module

post-build:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/doc && make plaintext html_chunked
.endif

post-install:
	@${LN} -fs ${PREFIX}/sbin/mount_fusefs /usr/sbin
.if ${PORT_OPTIONS:MAUTOSETUP} && !defined(PACKAGE_BUILDING)
	@${ECHO} "Modifying global startup config files and loading module..."
	@${SH} ${WRKDIR}/${SETUP}
.else
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/kmod/html
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/plaintext_out/$i ${DOCSDIR}/kmod
.endfor
.for i in ${HTML_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/html_chunked_out/$i ${DOCSDIR}/kmod/html
.endfor
.endif

.include <bsd.port.post.mk>
