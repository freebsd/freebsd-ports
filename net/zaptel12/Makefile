# Ports collection makefile for:	zaptel
# Date created:				29 April 2004
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zaptel
PORTVERSION=	0.11
CATEGORIES=	misc
MASTER_SITES=	http://www.pbxpress.com/~gonzo/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A FreeBSD Driver for FXO, FXS, BRI and PRI Telephony Cards

LIB_DEPENDS=	newt.51:${PORTSDIR}/devel/newt

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386

PKGMESSAGE=	${WRKSRC}/.MESSAGE
MAKE_ENV=	KMODDIR=${PREFIX}/lib/zaptel

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	"does not build on FreeBSD \< 5.x"
.endif

pre-everything::
	@if [ ! -f /usr/src/sys/Makefile ]; then \
		${ECHO_MSG} ">> The zaptel port needs FreeBSD kernel source code to compile."; \
		${ECHO_MSG} ">> Please install FreeBSD kernel source code in /usr/src/sys."; \
		${FALSE}; \
	fi

post-patch:
	@${REINPLACE_CMD} -e "s|<getopt.h>|<unistd.h>|g" \
		${WRKSRC}/test/ztmonitor.c ${WRKSRC}/test/zttool.c \
		${WRKSRC}/ztcfg/ztcfg.c

pre-su-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/zaptel.sh > \
		${WRKDIR}/zaptel.sh.sample
	@${MKDIR} ${PREFIX}/lib/zaptel

post-install:
	@${TOUCH} ${PREFIX}/lib/zaptel/linker.hints
	@${INSTALL_SCRIPT} ${WRKDIR}/zaptel.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
