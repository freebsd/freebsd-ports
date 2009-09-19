# New ports collection makefile for:	uhidd
# Date created:		2009-08-07
# Whom:			Kai Wang <kaiwang27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uhidd
PORTVERSION=	0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~kaiw/distfiles/

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	Userland USB HID device driver using libusb20

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	DEVD "Install devd files" on

KMODDIR?=	/boot/modules

USE_RC_SUBR=	uhidd

MAN4=		uvhid.4
MAN8=		uhidd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
BROKEN=		Does not build with the old USB stack
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if !defined(WITHOUT_DEVD)
PLIST_SUB+=	PL_DEVD=""
.else
PLIST_SUB+=	PL_DEVD="@comment "
.endif

SUB_FILES+=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhidd/uhidd ${PREFIX}/sbin/uhidd
	${INSTALL_KLD} ${WRKSRC}/uvhid/uvhid.ko ${KMODDIR}/uvhid.ko
	${INSTALL_MAN} ${WRKSRC}/uhidd/uhidd.8 ${PREFIX}/man/man8/uhidd.8
	${INSTALL_MAN} ${WRKSRC}/uvhid/uvhid.4 ${PREFIX}/man/man4/uvhid.4
.if !defined(WITHOUT_DEVD)
	${MKDIR} ${PREFIX}/etc/devd
	${REINPLACE_CMD} -Ee \
		"s%/usr/local%${PREFIX}%" ${WRKSRC}/uhidd/uhidd-devd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/uhidd/uhidd-devd.conf.sample ${PREFIX}/etc/devd/
	@if [ ! -f ${PREFIX}/etc/devd/uhidd-devd.conf ]; then \
		${CP} -p ${PREFIX}/etc/devd/uhidd-devd.conf.sample \
			${PREFIX}/etc/devd/uhidd-devd.conf; \
	fi
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
