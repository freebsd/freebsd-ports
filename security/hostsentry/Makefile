# New ports collection makefile for:   hostsentry
# Date created:        7 February 2003
# Whom:                Andre Ramos <andre.ramos@netcabo.pt>
#
# $FreeBSD$
#

PORTNAME=	hostsentry
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netsys.com/len/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/IDS

MAINTAINER=	mranner@inode.at
COMMENT=	A Login Anomaly Detector

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|' ${.CURDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.BUGS \
	${WRKSRC}/README.credits \
	${WRKSRC}/README.install \
	${WRKSRC}/README.intro \
	${WRKSRC}/README.modules \
	${WRKSRC}/README.paper \
	${WRKSRC}/README.technical \
	${WRKSRC}/README.why_python \
	${WRKSRC}/README.wtmp \
	${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
