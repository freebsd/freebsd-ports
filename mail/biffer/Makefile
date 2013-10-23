# Created by: jsellens
# $FreeBSD$

PORTNAME=	biffer
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.generalconcepts.com/resources/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Better mail notification server

RUN_DEPENDS=	xmsg:${PORTSDIR}/x11/xmsg

MAKE_JOBS_UNSAFE=	yes

MAN1=		biffopt.1
MAN8=		biffer.8 biffer_comsat.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/biffer_comsat/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biffer/biffer ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/biffopt/biffopt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/biffopt/biffopt.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/biffer/biffer.8 ${MAN8PREFIX}/man/man8
	cd ${WRKSRC}/biffer_comsat && ${MAKE} ${MFLAGS} install

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
	    POST-INSTALL

.include <bsd.port.post.mk>
