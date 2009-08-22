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
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lupe@lupe-christoph.de
COMMENT=	A Port Knocking implementation, both daemon and client

BUILD_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message
PATCH_STRIP=	-p1

INSTALL_TARGET=	installdirs install-exec install-data

MAN1=	knock.1
MAN5=	knockcf.5 doormand.cf.5 guestlist.5
MAN8=	doormand.8

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message doormand.cf.EXAMPLE
USE_RC_SUBR=	doorman.sh

pre-patch:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/doormand.c

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

.include <bsd.port.mk>
