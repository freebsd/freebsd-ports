# New ports collection makefile for:	sancp
# Date created:				10 Feb 2005
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	sancp
PORTVERSION=	1.6.1
CATEGORIES=	security
MASTER_SITES=	http://www.metre.net/files/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A network connection profiler

ALL_TARGET=	final
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

PORTDOCS=	CHANGES INSTALL ISSUES README SETUP fields.LIST

.include <bsd.port.pre.mk>

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/sancp.sh > ${WRKDIR}/sancp.sh

post-install:
	${SH} ${PKGINSTALL}
	${INSTALL_PROGRAM} ${WRKSRC}/sancp ${PREFIX}/bin
	${INSTALL_SCRIPT} -m 755 ${WRKDIR}/sancp.sh ${PREFIX}/etc/rc.d/sancp.sh
.for f in sancp.conf
	${INSTALL_DATA} ${WRKSRC}/etc/sancp/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
	${INSTALL_DATA} ${WRKSRC}/etc/sancp/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} LICENSE ${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${SED} 's|%%PREFIX%%|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
