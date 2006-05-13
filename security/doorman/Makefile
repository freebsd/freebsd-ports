# New ports collection makefile for:	doorman
# Date created:				08 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	doorman
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doorman
EXTRACT_SUFX=	.tgz

MAINTAINER=	lupe@lupe-christoph.de
COMMENT=	A Port Knocking implementation, both daemon and client

BUILD_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

# doormand does not work with the FreeBSD 4.x version of libpcap.
# Require the ports version.
.if ${OSVERSION} < 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
PATCH_STRIP=	-p1

INSTALL_TARGET=	installdirs install-exec install-data

MAN1=	knock.1
MAN5=	knockcf.5 doormand.cf.5 guestlist.5
MAN8=	doormand.8

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message doormand.cf.EXAMPLE
USE_RC_SUBR=	doorman.sh

pre-patch:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/doormand.c

post-configure:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's,-lpcap,${LOCALBASE}/lib/libpcap.a,' \
		${WRKSRC}/Makefile
.endif

post-install:
	${RM} -f ${PREFIX}/etc/doormand/ipf_add
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_add.atend ${PREFIX}/etc/doormand/ipf_add.atend
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_add.before_block ${PREFIX}/etc/doormand/ipf_add.before_block
	${INSTALL_SCRIPT} ${FILESDIR}/ipf_delete ${PREFIX}/etc/doormand/ipf_delete
	${INSTALL_DATA} ${WRKDIR}/doormand.cf.EXAMPLE ${PREFIX}/etc/doormand/doormand.cf.EXAMPLE
	@for man in ${MAN1}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man1; \
	done
	@for man in ${MAN5}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man5; \
	done
	@for man in ${MAN8}; do \
		${INSTALL_MAN} -C ${WRKSRC}/$$man ${PREFIX}/man/man8; \
	done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
