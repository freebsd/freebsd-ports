# New ports collection makefile for:	ipvs
# Date created:		Jun 11 2005
# Whom:			clement@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ipvs
PORTVERSION=	0.4.0
CATEGORIES=	net
MASTER_SITES=	http://dragon.linux-vs.org/~dragonfly/software/
DISTNAME=	ipvs_freebsd-${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	FreeBSD port of Linux Virtual Server

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SRCDIR?=	/usr/src

MAN8=		ipvsadm.8 ipvsadm-restore.8 ipvsadm-save.8
MAKE_ENV+=	MKDIR="${MKDIR}" KMODDIR="/boot/modules"

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

.if ${OSVERSION} == 503001
FREEBSD_VERSION=	5.3
.elif (${OSVERSION} == 504000 || defined(TRY_STABLE)) && !defined(PACKAGE_BUILDING)
FREEBSD_VERSION=	5.4
.else
IGNORE=	: You need a patched 5.3-RELEASE of 5.4-RELEASE src tree in ${SRCDIR}
.endif

patch-system: extract
	@${FIND} ${WRKSRC}/patch/${FREEBSD_VERSION}-RELEASE -type f \
		-name "*.patch" -exec ${PATCH} -p0 -d ${SRCDIR} -i {} \;

pre-everything::
	@${ECHO_CMD} "LVS on FreeBSD works only with 5.3-RELEASE and 5.4-RELEASE."
	@${ECHO_CMD} "However it may work on 5-STABLE. If you are running FreeBSD 5.4-STABLE, define"
	@${ECHO_CMD} "TRY_STABLE and check if patches apply correctly to your src tree"
	@${ECHO_CMD} "To build ipvs, I strongly encourage you to follow these instructions"
	@${ECHO_CMD} "      1. checkout supported src tree"
	@${ECHO_CMD} "      2. run \"make patch-system\""
	@${ECHO_CMD} "      3. configure and build your kernel. (you need support of NetFilter"
	@${ECHO_CMD} "         sockopt, add \"options NF_SOCKOPT\")"
	@${ECHO_CMD} "      4. Install your freshly compiled kernel"
	@${ECHO_CMD} "      5. install the port"
	@${ECHO_CMD} "      6. reboot your system"

post-patch:
	@${INSTALL_DATA} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.post.mk>
