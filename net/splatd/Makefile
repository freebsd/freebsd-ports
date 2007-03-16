# New ports collection makefile for:	splatd
# Date created:		26 September 2005
# Whom:			Landon Fuller <landonf@opendarwin.org>
#
# $FreeBSD$

PORTNAME=	splatd
PORTVERSION=	1.1.1
CATEGORIES=	net
MASTER_SITES=	http://dpw.threerings.net/projects/splat/
DISTNAME=	splat-${PORTVERSION}

MAINTAINER=	snb@threerings.net
COMMENT=	Splat is the Scalable Periodic LDAP Attribute Transmogrifier

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ZConfig:${PORTSDIR}/devel/py-zconfig \
		${PYTHON_SITELIBDIR}/ldap:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_RC_SUBR=	splatd.sh
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
MAN5=		splat.conf.5
MAN8=		splatd.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/splat.conf ${PREFIX}/etc/splat.conf.sample
	${MV} -f ${PREFIX}/bin/splatd ${PREFIX}/sbin/splatd
	${INSTALL_MAN} ${WRKSRC}/docs/man/splat.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/man/splatd.8 ${MANPREFIX}/man/man8

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${DOCSDIR}/xhtml
.endif

.include <bsd.port.mk>
