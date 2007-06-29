# New ports collection makefile for:	py-bcfg2
# Date created:		1 June 2007
# Whom:			Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$
#

PORTNAME=	bcfg2
PORTVERSION=	0.9.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/bcfg/ \
		http://mirror.opensysadmin.com/bcfg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	A configuration management system written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/${PYLXML_EGG}:${PORTSDIR}/devel/py-lxml
RUN_DEPENDS+=	cheetah:${PORTSDIR}/devel/py-cheetah
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gamin.py:${PORTSDIR}/devel/py-gamin

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

MAN1=	bcfg2.1
MAN5=	bcfg2.conf.5
MAN8=	bcfg2-admin.8 bcfg2-build-reports.8 bcfg2-repo-validate.8 bcfg2-server.8 bcfg2-info.8

PORTDOCS=	AUTHORS COPYRIGHT ChangeLog README

post-patch:
	    @${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

PYLXML_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-lxml/Makefile -V PYLXML_EGG

.include <bsd.port.post.mk>
