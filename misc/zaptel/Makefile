# Ports collection makefile for:	zaptel
# Date created:				29 April 2004
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zaptel
PORTVERSION=	0.9
CATEGORIES=	misc
MASTER_SITES=	http://www.portaone.com/~sobomax/
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
BROKEN=		"FreeBSD versions below 5.x is not supported yet. If you can add support please do it and send your patches to Alexander Timoshenko <gonzo@portaone.com>. We will integrate into the driver. Thanks!"
.endif

pre-everything::
	@if [ ! -f /usr/src/sys/Makefile ]; then \
		${ECHO_MSG} ">> The zaptel port needs FreeBSD kernel source code to compile."; \
		${ECHO_MSG} ">> Please install FreeBSD kernel source code in /usr/src/sys."; \
		${FALSE}; \
	fi

pre-install:
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
