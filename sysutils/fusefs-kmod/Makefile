# New ports collection makefile for:	fusefs-kmod
# Date created:				08 October 2005
# Whom:					Anish Mistry <amistry@am-productions.biz>
#
# $FreeBSD$
#

PORTNAME=	fusefs
DISTVERSION=	0.3.9-pre1.20080208
PORTREVISION=	5
CATEGORIES=	sysutils kld
MASTER_SITES=	http://mercurial.creo.hu/repos/fuse4bsd-hg/index.cgi/archive/
PKGNAMESUFFIX=	-kmod
DISTNAME=	${HG_SHORTREV}
DIST_SUBDIR=	fuse4bsd

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Kernel module for fuse

BUILD_DEPENDS=	fusefs-libs>2.4.1:${PORTSDIR}/sysutils/fusefs-libs

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	deplate:${PORTSDIR}/textproc/ruby-deplate
.endif

USE_RC_SUBR=	fusefs
KMODDIR?=	${PREFIX}/modules
PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${MANPREFIX}/man/man" \
		KMODDIR="${KMODDIR}" SYSDIR="${SRC_BASE}/sys" \
		MOUNT="${SRC_BASE}/sbin/mount"
WRKSRC=		${WRKDIR}/fuse4bsd-${HG_SHORTREV}
DISABLE_SIZE=	yes

SRC_BASE?=	/usr/src
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

OPTIONS=	AUTOSETUP "Automatic global config file setup" off

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires the Kernel source to be installed. Set SRC_BASE if it is not in /usr/src
.endif
.if !exists(${SRC_BASE}/sbin/mount)
IGNORE=		requires the userland sources to be installed. Set SRC_BASE if it is not in /usr/src
.endif

.if defined(WITH_AUTOSETUP)
SUB_FILES+=	${SETUP}
.else
SUB_FILES+=	pkg-message
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/deplate.rb/deplate/g' \
		${WRKSRC}/doc/Makefile

post-configure:
	@${CP} ${LOCALBASE}/include/fuse/fuse_kernel.h ${WRKSRC}/fuse_module

post-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && make plaintext html_chunked
.endif

pre-su-install:
	@${MKDIR} ${KMODDIR}

post-install:
	@${LN} -fs ${PREFIX}/sbin/mount_fusefs /usr/sbin
.if defined(WITH_AUTOSETUP) && !defined(PACKAGE_BUILDING)
	@${ECHO} "Modifying global startup config files and loading module..."
	@${SH} ${WRKDIR}/${SETUP}
.else
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
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
