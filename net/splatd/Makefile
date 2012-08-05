# New ports collection makefile for:	splatd
# Date created:		26 September 2005
# Whom:			Landon Fuller <landonf@opendarwin.org>
#
# $FreeBSD$

PORTNAME=	splatd
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	snb@FreeBSD.org
COMMENT=	Splat is the Scalable Periodic LDAP Attribute Transmogrifier

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig \
		${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	splat
USE_RC_SUBR=	splatd
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
